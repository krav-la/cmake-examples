# Qt CMake Compilation
## Upgrade WSL to Ubuntu 22.04
Проверить версию Ubuntu можно вызовом следующей команды
```
$ lsb_release -a
```
При версии ниже 22.04 необходимо выполнить обновление
```
$ sudo do-release-upgrade
```
> Может понадобиться сначала изменить поведение release upgrader. В фале /etc/update-manager/release-upgrades должно стоять значение `Prompt=lts`
## Qt6 Installation
Установка Qt6 с QML в WSL Ubuntu 22.04
```
$ sudo apt update
$ sudo apt upgrade
$ sudo apt-get install qt6-base-dev qt6-declarative-dev qt6-wayland qml6-module-qtquick qml6-module-qtqml-workerscript qml6-module-qtquick-templates qml6-module-qtquick-controls
```