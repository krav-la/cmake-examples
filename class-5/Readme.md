# Компиляция Qt из исходного кода
## Клонирование исходного кода Qt
> Путь к клонируемому репозиторию `path_to_repo` не должен содержать пробелов или особых символов и быть максимально коротким. Это позволит избежать проблем во время компиляции

```
$ cd <path_to_repo>
$ git clone git://code.qt.io/qt/qt5.git
```
## Зависимости
Необходимо установить следующие компоненты
- [python 3](https://www.python.org/downloads/windows/)
- [ninja](https://github.com/ninja-build/ninja/releases/tag/v1.11.1)
- [perl](https://strawberryperl.com/download/5.32.1.1/strawberry-perl-5.32.1.1-64bit.msi)

> Пути ко всем зависимостям должны быть прописаны в `PATH`

Помимо вышеуказанных зависимостей стоит добавить в `PATH` пути к `cl.exe` и `rc.exe` 
- Для `cl.exe` обычно `C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.35.32215\bin\Hostx64\x64`
- Для `rc.exe` обычно `C:\Program Files (x86)\Windows Kits\10\bin\10.0.22621.0\x64`

## Qt6
### Настройка окружения
Во избежание проблем с поиском библиотек и исполняемых файлов в процессе сборки стоит создать скрипт `qt6vars.cmd` для настройки окружения аналогично `терминалу Visual Studio` со следующим содержимым
```
REM Set up Microsoft Visual Studio 2019, where <arch> is amd64, x86, etc.
CALL "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" amd64
SET _ROOT=C:\qt5\
SET PATH=%_ROOT%\qtbase\bin;%PATH%
SET _ROOT=
```

Запуск скрипта осуществляется через команду вида
```
$ %SystemRoot%\system32\cmd.exe /E:ON /V:ON /k C:\Qt\qt6vars.cmd
```
Будет запущен новый терминал с уже настроенным окружением

### Сборка
- Перейти в директорию проекта и выбрать версию Qt
    ```
    $ cd <qt_source_folder> 
    $ git checkout 6.5
    ```
- Во избежание проблем с конфигурацией подмодулей проекта необходимо разрешить длинные пути в глобальных настройках Git
    ```
    $ git config --global core.longpaths true
    ```
- Инициализировать подмодули
    ```
    $ perl init-repository
    ```
- Сконфигурировать CMake-проект
    ```
    $ configure -static -prefix %CD%\qtbase
    ```
- Запустить сборку
    ```
    $ cmake --build . --parallel
    ```

### Clean
Для сброса результатов сборки можно удалить `CMakeCache.txt`

## Qt5
### Настройка окружения
Аналогично Qt6 создаётся скрипт `qt5vars.cmd` для настройки окружения
```
REM Set up Microsoft Visual Studio 2017, where <arch> is amd64, x86, etc.
CALL "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" amd64
SET _ROOT=C:\qt5
SET PATH=%_ROOT%\qtbase\bin;%_ROOT%\gnuwin32\bin;%PATH%
REM Uncomment the below line when using a git checkout of the source repository
REM SET PATH=%_ROOT%\qtrepotools\bin;%PATH%
SET _ROOT=
```

Запуск скрипта осуществляется через команду вида
```
$ %SystemRoot%\system32\cmd.exe /E:ON /V:ON /k C:\Qt\qt5vars.cmd
```
Будет запущен новый терминал с уже настроенным окружением

### Сборка
- Перейти в директорию проекта и выбрать версию Qt
    ```
    $ cd <qt_source_folder> 
    $ git checkout 5.15
    ```
- Во избежание проблем с конфигурацией подмодулей проекта необходимо разрешить длинные пути в глобальных настройках Git
    ```
    $ git config --global core.longpaths true
    ```
- Инициализировать подмодули
    ```
    $ perl init-repository
    ```
- Создать директорию сборки
    ```
    $ mkdir build
    $ cd build
    ```
- Сконфигурировать проект
    ```
    $ ..\configure -debug -nomake examples -nomake tests -skip qtwebengine -opensource
    ```
- Запустить сборку
    ```
    $ nmake
    ```