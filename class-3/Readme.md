# Release and Debug build types
Для переключения между типами сборки (Debug/Release) необходимо указать допустимые типы при конфигурации проекта

## Для MSVC (Multiconfig Build System)
- Указывается список допустимых вариантов конфигурации через переменную `CMAKE_CONFIGURATION_TYPES`

    ```
    $ cd <корневая_директория_проекта>
    $ cmake.exe -B build -DCMAKE_CONFIGURATION_TYPES="Debug;Release"
    ```
- Желаемая конфигурация выбирается при запуске сборке через опцию `--config`

    ```
    $ cmake.exe --build ./build --config Release
    ```
## Для GCC
- Желаемая конфигурация выбирается в момент конфигурации через переменную `CMAKE_BUILD_TYPE`
    ```
    $ cd <корневая_директория_проекта>
    $ cmake -B build -DCMAKE_BUILD_TYPE="Release"
    $ cmake --build ./build
    ```

## Generator Expressions

`${CMAKE_BINARY_DIR}` - Переменная. Значение устанавливается в момент конфигурации.

`$<CONFIG>` - Выражение генератора. Значение устанавливается в момент генерации.

## if/else

### Синтаксис

```
if(<условное_выражение>)
    
elseif(<условное_выражение>)

else()

endif()
```

### Возможные результаты условий
| True	| False	|
|---	|---	|
| TRUE	| FALSE	|
| set  	| unset	|
| ON  	| OFF  	|
| 1  	| 0  	|

### Пример
```
# if requires a variable without ${}
set(COMPILER_TYPE ${CMAKE_CXX_COMPILER_ID})
if(COMPILER_TYPE STREQUAL "GNU")
    # message("The current compiler is GNU")
else()
    # message("Any other compiler")
endif()
```