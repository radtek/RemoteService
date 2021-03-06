#define VERSION_MAJOR_FILE     2
#define VERSION_MINOR_FILE     0
#define VERSION_REVISION_FILE  5
#define VERSION_BUILD_FILE     16

#define FILEV VERSION_MAJOR_FILE, VERSION_MINOR_FILE,VERSION_REVISION_FILE,VERSION_BUILD_FILE

#define VERSION_MAJOR_PROD     2
#define VERSION_MINOR_PROD     0
#define VERSION_REVISION_PROD  5
#define VERSION_BUILD_PROD     1

#define STRINGIZE2(s) #s
#define STRINGIZE(s) STRINGIZE2(s)

#define PRODUCTV VERSION_MAJOR_PROD, VERSION_MINOR_PROD,VERSION_REVISION_PROD,VERSION_BUILD_PROD
#define PRODUCTV_STRING STRINGIZE(VERSION_MAJOR_PROD) STRINGIZE(.) STRINGIZE(VERSION_MINOR_PROD) STRINGIZE(.) STRINGIZE(VERSION_REVISION_PROD) STRINGIZE(.) STRINGIZE(VERSION_BUILD_PROD)
