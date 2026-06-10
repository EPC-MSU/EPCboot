**English**

The aim of this program is the loading firmware, cryptographic key or device identify information to UltraRay or XIMC 
controllers.

*Usage*: 

    epcboot -K -a PORT_URL -k KEY
    To set cryptographic key on device.
    OR
    epcboot -I -a PORT_URL -k KEY -s SERIAL -v MAJOR.MINOR.REVISION
    To set serial number and hardware version on device.
    OR
    epcboot -F -a PORT_URL -f FILE
    To set new firmware on device.
    OR
    epcboot -h

- *PORT_URL* is device name.
  Device name has form "com:port" or "emu:file" for virtual device.
  In case of USB-COM port the "port" is the OS device name.
  For example:
  ```
  "com:///\\.\COM12",
  "com:\\.\COM12",
  "com:///dev/tty/ttyACM34",
  "emu:///var/lib/ximc/virtual56.dat",
  "emu:///c:/temp/virtual56.dat",
  "emu:///c:/temp/virtual56.dat?serial=123"
  ```
  WARNING: Use simlinks instead of using /dev/tty directly.
- *KEY* is a cryptographic key.
- *SERIAL* is a device serial number.
- *FILE* is a path to firmware file. Do not use "~" in this path.

To build this program, you need to:
- **on Linux** - go to src subdirectory and run the following commands:
  ```bash
  $ cmake
  $ make
  ```
- **on Windows** - use CMake-gui to generate a project for Microsoft Visual Studio 2013 (https://www.johnlamp.net/cmake-tutorial-3-gui-tool.html). Open the project and build.

This program launch from console, and write LOG to stderr.

Exchange with target device may be tested:
- create BOOTLOG environment variable,
- place log file path to this variable,
- start application that use library,
- read log file.

**Русский (Russian)**

Это приложение предназначено для того, чтобы заливать прошивки, криптоключи и информацию об устройстве в контроллеры UltraRay и XIMC.

*Использование*: 

    epcboot -K -a PORT_URL -k KEY
    To set cryptographic key on device.
    OR
    epcboot -I -a PORT_URL -k KEY -s SERIAL -v MAJOR.MINOR.REVISION
    To set serial number and hardware version on device.
    OR
    epcboot -F -a PORT_URL -f FILE
    To set new firmware on device.
    OR
    epcboot -h

- *PORT_URL* - имя устройства.
  Имя устройства имеет вид "com:port" или "emu:file" для виртуального устройства.
  Для USB-COM устройства "port" это имя устройства в ОС. Например:
  ```
  "com:///\\.\COM12",
  "com:\\.\COM12",
  "com:///dev/tty/ttyACM34",
  "emu:///var/lib/ximc/virtual56.dat",
  "emu:///c:/temp/virtual56.dat",
  "emu:///c:/temp/virtual56.dat?serial=123"
  ```
  Не используйте com:///dev/tty для обращения к устройству, лучше используйте символические ссылки.
- *KEY* - криптографический ключ.
- *SERIAL* - серийный номер устройства.
- *FILE* - путь к прошивке. Не используйте "~" в пути к файлу.

Сборка программы:
- **под Linux** - в поддиректории src запустить команды:
  ```bash
  $ cmake .
  $ make
  ```
- **под Windows** - с помощью CMake-gui сгенерировать проект для Microsoft Visual Studio 2013 (см. https://www.johnlamp.net/cmake-tutorial-3-gui-tool.html).
  Записываем откуда брать исходники, куда класть бинарники и нажимаем кнопку Configue.
  После этого CMake-gui предложит выбрать компилятор. По умолчанию MSVS-2013, Win32.
  **Этот компилятор следует оставить.**
  После Configure нажать Generate.
  Открыть проект и собрать

Программа запускается из консоли, синтаксис командной строки в разделе "Использование", лог пишется в stderr.

Обмен с целевым устройством, использующим это приложение, может быть протестирован следующим образом:
- создаём переменную окружения BOOTLOG,
- помещаем в неё путь к лог-файлу,
- запускаем программу, использующую библиотеку,
- читаем лог.
