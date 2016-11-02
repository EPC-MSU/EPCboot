#ifndef _COMMANDS_H
#define _COMMANDS_H

/*
 * This file is autogenerated.
 * Changes made to this file can be overwritten.
 */

#if defined(__cplusplus)
extern "C"
{
#endif

#pragma pack(push, 1)

/*
 * Protocol version
 */
#define PROTOCOL_VERSION 0.3.0
#define PROTOCOL_VERSION_Q "0.3.0"

/*
 * Command codes
 */
#define REST_CMD  0x74736572
#define WKEY_CMD  0x79656B77
#define CONN_CMD  0x6E6E6F63
#define DISC_CMD  0x63736964
#define WDAT_CMD  0x74616477
#define GETI_CMD  0x69746567
#define GBLV_CMD  0x766C6267
#define HASF_CMD  0x66736168
#define GOFW_CMD  0x77666F67
#define IRND_CMD  0x646E7269
#define SSER_CMD  0x72657373
#define GSER_CMD  0x72657367
#define UPDF_CMD  0x66647075
#define GETS_CMD  0x73746567
#define GDMY_CMD  0x796D6467
#define SDMY_CMD  0x796D6473
#define GINF_CMD  0x666E6967
#define RBLD_CMD  0x646C6272

/*
 * ERRC, ERRD, ERRV codes must be always
 */
#define ERRC_CMD  0x63727265
#define ERRD_CMD  0x64727265
#define ERRV_CMD  0x76727265

/*
 * All command flags below
 */


/*
 * All structures below
 */

typedef struct {
  uint8_t reserved[8]; /**< \~english  \~russian  */
} in_end_session_t;
typedef struct {
  uint8_t reserved[4]; /**< \~english  \~russian  */
} dummy_t;
typedef struct {
  uint8_t reserved[8]; /**< \~english  \~russian  */
} in_start_session_t;
typedef struct {
  uint8_t Result; /**< \~english  \~russian  */
  uint8_t reserved[8]; /**< \~english  \~russian  */
} out_end_session_t;
typedef struct {
  uint8_t Data[128]; /**< \~english  \~russian  */
  uint8_t reserved[8]; /**< \~english  \~russian  */
} write_data_t;
typedef struct {
  uint32_t SerialNumber; /**< \~english  \~russian  */
} get_serial_number_t;
typedef struct {
  uint32_t SerialNumber; /**< \~english New board serial number. \~russian Новый серийный номер платы. */
  uint8_t Key[32]; /**< \~english Protection key (256 bit). \~russian Ключ защиты для установки серийного номера (256 бит). */
  uint8_t HardwareMajor; /**< \~english The major number of the hardware version. \~russian Основной номер версии железа. */
  uint8_t HardwareMinor; /**< \~english Minor number of the hardware version. \~russian Второстепенный номер версии железа. */
  uint16_t HardwareBugfix; /**< \~english Number of edits for this release of hardware. \~russian Номер правок этой версии железа. */
  uint8_t reserved[4]; /**< \~english  \~russian  */
} set_serial_number_t;
typedef struct {
  uint8_t Key[32]; /**< \~english  \~russian  */
  uint8_t reserved[8]; /**< \~english  \~russian  */
} in_write_key_t;
typedef struct {
  uint8_t Key[16]; /**< \~english Random key. \~russian Случайный ключ. */
  uint8_t reserved[2]; /**< \~english  \~russian  */
} init_random_t;
typedef struct {
  uint8_t Result; /**< \~english  \~russian  */
  uint8_t reserved[8]; /**< \~english  \~russian  */
} out_start_session_t;
typedef struct {
  uint8_t Manufacturer[16]; /**< \~english Manufacturer name. The name is set by the manufacturer. \~russian Имя производителя. Устанавливается производителем. */
  uint8_t ProductName[16]; /**< \~english Product name. The name is set by the manufacturer. \~russian Название продукта. Устанавливается производителем. */
  uint8_t ControllerName[16]; /**< \~english User controller name. This name can be set by user via additional command. \~russian Пользовательское имя контроллера. Может быть установлено пользователем с помощью отдельной команды. */
  uint8_t HardwareMajor; /**< \~english The major number of the hardware version. \~russian Основной номер версии железа. */
  uint8_t HardwareMinor; /**< \~english Minor number of the hardware version. \~russian Второстепенный номер версии железа. */
  uint16_t HardwareBugfix; /**< \~english Number of edits for this release of hardware. \~russian Номер правок этой версии железа. */
  uint8_t BootloaderMajor; /**< \~english Bootloader major version number. \~russian Мажорный номер версии загрузчика. */
  uint8_t BootloaderMinor; /**< \~english Bootloader minor version number. \~russian Минорный номер версии загрузчика. */
  uint16_t BootloaderBugfix; /**< \~english Bootloader release version number. \~russian Номер релиза версии загрузчика. */
  uint8_t FirmwareMajor; /**< \~english Firmware major version number. \~russian Мажорный номер версии прошивки. */
  uint8_t FirmwareMinor; /**< \~english Firmware minor version number. \~russian Минорный номер версии прошивки. */
  uint16_t FirmwareBugfix; /**< \~english Firmware bugfix version number. \~russian Номер багфикса версии прошивки. */
  uint32_t SerialNumber; /**< \~english Device serial number. \~russian Серийный номер изделия. */
  uint8_t reserved[8]; /**< \~english  \~russian  */
} get_identity_information_t;
typedef struct {
  uint8_t Result; /**< \~english Result of command. \~russian Результат выполнения команды. */
  uint8_t reserved[8]; /**< \~english  \~russian  */
} out_write_key_t;
typedef struct {
  uint8_t Result; /**< \~english  \~russian  */
  uint8_t reserved[8]; /**< \~english  \~russian  */
} goto_firmware_t;
typedef struct {
  uint8_t Result; /**< \~english  \~russian  */
  uint8_t reserved[8]; /**< \~english  \~russian  */
} has_firmware_t;
typedef struct {
  uint8_t Manufacturer[4]; /**< \~english  \~russian  */
  uint8_t ManufacturerId[2]; /**< \~english  \~russian  */
  uint8_t ProductDescription[8]; /**< \~english  \~russian  */
  uint8_t Major; /**< \~english  \~russian  */
  uint8_t Minor; /**< \~english  \~russian  */
  uint16_t Release; /**< \~english  \~russian  */
  uint8_t reserved[12]; /**< \~english  \~russian  */
} get_device_information_t;
typedef struct {
  uint8_t reserved[48]; /**< \~english  \~russian  */
} get_status_t;
typedef struct {
  uint8_t Major; /**< \~english  \~russian  */
  uint8_t Minor; /**< \~english  \~russian  */
  uint16_t Release; /**< \~english  \~russian  */
} get_bootloader_version_t;

#pragma pack(pop)

/*
 * This structure is for storage all accessors parameters.
 */
typedef struct
{
  /*
   * Accessors structures only.
   */
  dummy_t DMY;

} settings_storage_t;

extern settings_storage_t Commands_SettingsStorage;

extern uint16_t Commands_GetInputSize(uint32_t cmd);
extern uint16_t Commands_GetOutputSize(uint32_t cmd);

#if defined(__cplusplus)
};
#endif

#endif  // _COMMANDS_H