# Hello Subdirectory
Простой пример использования CMake для сборки исполняемого файла из нескольких файлов, расположенных в разных директориях проекта.

### Описание
Проект состоит из корневой директории и поддиректории `common`.

Поддиректория `common` содержит свой CMakeLists.txt, описывающий правила сборки исходных файлов, находящихся в данной директории.

Новые поддиректории добавляются в сборку следующим образом

```
add_subdirectory(common)
```

### common/CMakeLists.txt
Цель сборки директори `common` - библиотека объектных файлов. В свойства данной библиотеки прописан путь к заголовочным файлам с интерфейсом `PUBLIC` для возможности неявной передачи этого пути всем целям, зависящим от исходного кода `common`.

```
add_library(common OBJECT ${SOURCES})
target_include_directories(common PUBLIC ${CMAKE_SOURCE_DIR}/common)

```

### Линковка зависимостей
Информация о линкуемых файлах задаётся следующим образом в корневом CMakeLists.txt

```
add_executable(${BINARY_NAME} ${SOURCES})
# Link common
target_link_libraries(${BINARY_NAME} common)
```

Причём, путь к заголовку MyLogger.h неявно передаётся цели `${BINARY_NAME}` через соответствующее свойство цели `common`
### Изменение пути к артефактам
При необходимости изменить путь к выходным артефактам сборки можно при помощи свойства `RUNTIME_OUTPUT_DIRECTORY`

```
set(BIN_OUTPUT_PATH 
    "${CMAKE_BINARY_DIR}/${CMAKE_CXX_COMPILER_ID}-${CMAKE_CXX_COMPILER_VERSION}/bin"
)

...

set_target_properties(${BINARY_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${BIN_OUTPUT_PATH}
)
```

## Сборка
Директорию сборки можно создать автоматически при запуске конфигурации с опцией `-B <путь_к_директории_сборки>`

`$ cmake -B build .`

`$ cd build`

`$ cmake --build .`









