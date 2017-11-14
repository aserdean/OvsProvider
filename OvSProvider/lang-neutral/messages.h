 // This is the header section
// The following are the message definitions.
//
//  Values are 32 bit values laid out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +---+-+-+-----------------------+-------------------------------+
//  |Sev|C|R|     Facility          |               Code            |
//  +---+-+-+-----------------------+-------------------------------+
//
//  where
//
//      Sev - is the severity code
//
//          00 - Success
//          01 - Informational
//          10 - Warning
//          11 - Error
//
//      C - is the Customer code flag
//
//      R - is a reserved bit
//
//      Facility - is the facility code
//
//      Code - is the facility's status code
//
//
// Define the facility codes
//


//
// Define the severity codes
//


//
// MessageId: MSG_USERSPACE_ERR
//
// MessageText:
//
// Event data: %1
//
#define MSG_USERSPACE_ERR                ((DWORD)0x00000064L)

//
// MessageId: MSG_USERSPACE_WAR
//
// MessageText:
//
// Event data: %1
//
#define MSG_USERSPACE_WAR                ((DWORD)0x00000065L)

//
// MessageId: MSG_USERSPACE_INFO
//
// MessageText:
//
// Event data: %1
//
#define MSG_USERSPACE_INFO               ((DWORD)0x00000066L)

//
// MessageId: MSG_USERSPACE_CRIT
//
// MessageText:
//
// Event data: %1
//
#define MSG_USERSPACE_CRIT               ((DWORD)0x00000067L)

//
// MessageId: MSG_USERSPACE_VERB
//
// MessageText:
//
// Event data: %1
//
#define MSG_USERSPACE_VERB               ((DWORD)0x00000068L)

//
// MessageId: MSG_DATAPATH_ERR
//
// MessageText:
//
// Event data: %1
//
#define MSG_DATAPATH_ERR                 ((DWORD)0x000000C8L)

//
// MessageId: MSG_DATAPATH_WAR
//
// MessageText:
//
// Event data: %1
//
#define MSG_DATAPATH_WAR                 ((DWORD)0x000000C9L)

//
// MessageId: MSG_DATAPATH_INFO
//
// MessageText:
//
// Event data: %1
//
#define MSG_DATAPATH_INFO                ((DWORD)0x000000CAL)

//
// MessageId: MSG_DATAPATH_CRIT
//
// MessageText:
//
// Event data: %1
//
#define MSG_DATAPATH_CRIT                ((DWORD)0x000000CBL)

//
// MessageId: MSG_DATAPATH_VERB
//
// MessageText:
//
// Event data: %1
//
#define MSG_DATAPATH_VERB                ((DWORD)0x000000CCL)

