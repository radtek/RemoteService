#pragma once
#include "qobject.h"

#include "BasicServer.h"
#include <qtcpserver.h>

namespace RW{
	namespace CORE{

		class JobScheduler;
		class WebSocketServer;
		class LocalServer;
		class TCPServer;

		class CommunicationServer :
			public QObject
		{
			Q_OBJECT
		private:
			LocalServer		*m_LocalServer;
			TCPServer		*m_TcpServer;
			std::shared_ptr<spdlog::logger> m_logger;
			QList<QObject*> m_ReceiverList;

		public:
			CommunicationServer(QObject *Parent);
			~CommunicationServer();

			void DisconectLater();

			void Register(QObject* Receiver);
			void Register(QObject* Receiver, CommandIds CommandId);
			void Unregister(QObject* Receiver);
			void UnregisterAll();

			virtual bool Listen(quint16 Port);
		public slots:
			/******************************************************************************************************************
			@autor Ivo Kunadt
			@brief
			@param Command
			@return void
			********************************************************************************************************************/
			virtual void OnDisconnect();

			/******************************************************************************************************************
			@autor Ivo Kunadt
			@brief
			@param Command
			@return void
			********************************************************************************************************************/
			virtual void OnSocketError(quint16 Error);

			/******************************************************************************************************************
			@autor Ivo Kunadt
			@brief
			@param Command
			@return void
			********************************************************************************************************************/
            void OnProcessMessage(Util::MessageReceiver Type, Util::Functions Func, QByteArray Data);

            /******************************************************************************************************************
            @autor Ivo Kunadt
            @brief
            @param Command
            @return void
            ********************************************************************************************************************/
            void OnRemoteHiddenHelperConnected();

		signals: 
			void NewMessage(Util::MessageReceiver Type, Util::Functions Func, QByteArray Data);
			void ProcessedMessage(AbstractCommand* Command);
			void SocketError(quint16 Error);
            void RemoteHiddenHelperConnected();
		};
	}
}
