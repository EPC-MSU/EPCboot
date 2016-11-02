#ifndef INC_PLATFORM_H
#define INC_PLATFORM_H

/*
 * Serial port support
 */

#include "metadata.h"

// return code on success
#define result_serial_ok 0

// return code on generic error
#define result_serial_error -1

// return code on device lost
#define result_serial_nodevice -2

// return code on timeout
#define result_serial_timeout -3

/*
 * Platform-specific serial port routines
 */
result_t open_port_serial (device_metadata_t *metadata, const char* name);

int close_port_serial (device_metadata_t *metadata);
int flush_port_serial (device_metadata_t *metadata);
ssize_t read_port_serial (device_metadata_t *metadata, void *buf, size_t amount);
ssize_t write_port_serial (device_metadata_t *metadata, const void *buf, size_t amount);

/*
 * Threading support
 */

/* Callback for user actions */
typedef void (*fork_join_thread_function_t)(void *arg);

/* Platform-specific fork/join function */
result_t fork_join (fork_join_thread_function_t function, int count, void* args, size_t arg_element_size);

void single_thread_wrapper_function(void *arg);

unsigned long long get_thread_id();

/*
 * Device enumeration support
 */

/* Callback for user actions */
typedef void (*enumerate_devices_directory_callback_t) (char* name, void* arg);

/* Platform-specific enumerator */
result_t enumerate_devices_directory (enumerate_devices_directory_callback_t callback, void* arg, int flags);

bool is_same_device (const char* name1, const char* name2);

/*
 * Error handling
 */
unsigned int get_system_error_code ();

wchar_t* get_system_error_str (int code);

void free_system_error_str (wchar_t* str);

/* specific nodevice errors */
int is_error_nodevice(unsigned int errcode);
void set_error_nodevice ();

/*
 * Misc
 */
int fix_usbser_sys(const char* device_name);

void URPC_CALLCONV msec_sleep(unsigned int msec);

void get_wallclock(time_t* sec, int* msec);
void get_wallclock_us(uint64_t* us);

/* Converts path to absolute (add leading slash on posix) */
void uri_path_to_absolute(const char *uri_path, char *abs_path, size_t len);

/* Sets default bindy keyfile location. Returns non-zero on success */
int set_default_bindy_key();

/*
 * Mutex
 */
typedef struct mutex_t mutex_t;

mutex_t* mutex_init(unsigned int nonce);
void mutex_close(mutex_t* mutex);
void mutex_lock(mutex_t* mutex);
void mutex_unlock(mutex_t* mutex);
bool mutex_islocked(mutex_t* mutex);

typedef struct net_enum_t
{
	mutex_t * mutex;	// mutex
	int server_count;	// server count
	int* device_count;	// array of number of found devices on each server
	char** addrs;		// array of strings with address of each server
	uint8_t*** pbufs;	// array of pointers to buffer for each server
} net_enum_t;

typedef struct netthread_state_t
{
	const char* addr;
	uint8_t** pbuf;
	int status;
	unsigned int devices_found;
} netthread_state_t;

/* Platform-specific thread launcher */
void single_thread_launcher(URPC_RETTYPE(URPC_CALLCONV *func)(void*), void *arg);

/* Platform-specific fork/join function with timeout*/
void fork_join_with_timeout(fork_join_thread_function_t function, int count, void* args, size_t arg_element_size, int timeout_ms, net_enum_t *net_enum);

#endif
