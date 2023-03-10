# Hello CMake
Простой пример использования CMake для сборки исполняемого файла из одного исходного файла

## Конфигурация проекта
В результате конфигурации будут созданы файлы, необходимые для сборки проекта. Например, `Makefile` для Linux или `.sln` файл для Win и т.п. 

`$ mkdir build`

`$ cd build`

`$ cmake ../`

## Сборка проекта
Сборка проекта осуществляется из директории, содержащей сгенерированные на предыдущем шаге файлы.

Можно воспользоваться опцией `--build` для автоматического выбора способа сборки

`$ cd build`

`$ cmake --build .`

Либо осуществить запуск сборки соответствующим инструментом в зависимости от файлов, созданных в результате конфигурации.

Так для Linux сборка осуществляется при помощи вызова `make`

`$ cd build`

`$ make`

А для Win можно воспользоваться `MSBuild`

`$ MSBuild.exe ./hello_cmake.sln`


## Результат сборки
Путь к собранному бинарному файлу будет указан в ходе сборки в следующем виде

`hello.vcxproj -> <путь_к_корню_проекта>\class-1\build\Debug\hello.exe`







