# Este documento permite añadir el repositorio oficial de Chirpstack V4
## Comando (para versiones de OS antiguas) para añadir la clave del repositorio
```sh
sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-keys 1CE2AFD36DBCCA00
```
**Problema**: apt-key no está soportado en los últimos OS
## Solución
### Descargamos y añadimos la clave GPG moderna
```sh
sudo mkdir -p /etc/apt/keyrings
sudo chmod 755 /etc/apt/keyrings
curl -fsSL 'https://keyserver.ubuntu.com/pks/lookup?op=get&search=0x1CE2AFD36DBCCA00' | gpg --dearmor | sudo tee /etc/apt/keyrings/chirpstack.gpg >/dev/null
```
### Le decimos a apt que ese repositorio se firma con esa clave:
```sh
echo "deb [signed-by=/etc/apt/keyrings/chirpstack.gpg] https://artifacts.chirpstack.io/packages/3.x/deb stable main " \  | sudo tee /etc/apt/sources.list.d/chirpstack.list >/dev/null
```
## Actualizamos los repositorios del sistema e instalamos
```sh
sudo apt update
sudo apt install chirpstack
```
