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
			public BasicServer
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

			virtual void PrepareIncomingConnection();
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
            virtual void OnProcessedMessage(Util::MessageReceiver Type, Util::Functions Func, QByteArray Data);



		signals: 
            void NewMessage(Util::Functions MessageType, QByteArray Message);
			void ProcessedMessage(AbstractCommand* Command);
			void SocketError(quint16 Error);
		};
	}
}
