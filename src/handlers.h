#ifndef _HANDLERS_H
#define _HANDLERS_H

/*
 * Other includes here.
 */
#include "commands.h"

#if defined(__cplusplus)
extern "C"
{
#endif

/*
 * Regular commands with input data must be below.
 */
void on_write_key(in_write_key_t *input, out_write_key_t *output);
void on_start_session(in_start_session_t *input, out_start_session_t *output);
void on_end_session(in_end_session_t *input, out_end_session_t *output);
void on_write_data(write_data_t *input);
void on_set_serial_number(set_serial_number_t *input);

/*
 * Regular commands without input data must be below.
 */
void on_reset(void);
void on_get_device_information(get_device_information_t *output);
void on_get_bootloader_version(get_bootloader_version_t *output);
void on_has_firmware(has_firmware_t *output);
void on_goto_firmware(goto_firmware_t *output);
void on_init_random(init_random_t *output);
void on_get_serial_number(get_serial_number_t *output);
void on_update_firmware(void);
void on_get_status(get_status_t *output);
void on_get_identity_information(get_identity_information_t *output);
void on_reboot_to_bootloader(void);

/*
 * Accessors like S*** handlers must be below.
 */
void on_set_dummy(dummy_t *input);

#if defined(__cplusplus)
};
#endif

#endif  // _HANDLERS_H