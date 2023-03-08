# Сборка Библиотек 
## Выбор конфигурации
Для подключения динамических библиотек в Win необходимо либо изменять исходный код приложения для объявления экспортированных символов (`__declspec(import)`/`__declspec(export)`), либо создавать `.def` файл, поэтому создание новой библиотеки через `add_library` с аргументом `SHARED` является недостаточным, в отличие от OS Linux.

Наиболее правильным вариантом переключения между статической и динамической версиями библиотеки является объявление цели без аргументов `STATIC/SHARED` и выборе конкретной конфигурации через опцию кэша `BUILD_SHARED_LIBS`.

В случае Windows также необходимо разрешить экспорт библиотечных символов через переменную `CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS`

### CMakeLists.txt
```
cmake_minimum_required(VERSION 3.16)
project(file_library)

file(GLOB SOURCES *.cpp)

add_library(file-mng ${SOURCES})
set_target_properties(file-mng PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)
target_include_directories(file-mng INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
```

### Static
```
$ cmake.exe -B build -DBUILD_SHARED_LIBS=FALSE .
```

### Shared
```
$ cmake.exe -B build -DCMAKE_WINDOWS_EXPORT_ALL_SYMBOLS=TRUE -DBUILD_SHARED_LIBS=TRUE .
```

> Без указания `BUILD_SHARED_LIBS` будет собрана статическая версия библиотеки (по умолчанию)