# Ledger Kusama app (Polkadot soon)
![stability-wip](https://img.shields.io/badge/stability-work_in_progress-lightgrey.svg)
[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)
[![CircleCI](https://circleci.com/gh/ZondaX/ledger-polkadot.svg?style=shield)](https://circleci.com/gh/ZondaX/ledger-polkadot)

This project contains the Kusama app for Ledger Nano S and X.

## *WARNING: WORK IN PROGRESS*
Note: At the moment, you should be able to:
- connect
- retrieve version number
- retrieve and show addresses
- sign supported transactions (not all are supported yet)

The purpose of this early release is to facilitate integration efforts and early testing.
 
This repository contains the Ledger Nano S/X app for Kusama / Polkadot

- Ledger Nano S/X BOLOS app
- Unit tests

App source code is linked as a submodule to align with Ledger's build infrastructure.

For development purposes, we recommend this complete repository (includes unit tests, tools, etc.) instead of the submodule.

# Building

At the moment, the only option is to build the app on your own. **Please only use a TEST DEVICE!** 

Once the app is ready and we reach v1.0.0, it will be submitted to Ledger so it is published in the app Catalog. 

## Get source
Apart from cloning, be sure you get all the submodules:
```
git submodule update --init --recursive
```

## Dependencies

#### Ledger Nano S

- This project requires Ledger firmware 1.5.5 

- The current repository keeps track of Ledger's SDK but it is possible to override it by changing the git submodule.

#### Docker CE

- Please install docker CE. The instructions can be found here: https://docs.docker.com/install/

#### Ubuntu Dependencies
- Install the following packages:
   ```
   sudo apt update && apt-get -y install build-essential git wget cmake \ 
  libssl-dev libgmp-dev autoconf libtool
   ```

#### OSX Dependencies
- Instal `brew` and `xcode`.

- You will also need:

   ```
   brew install libusb
   ```

  In OSX, python version is by default 2.7 and you will need python 3.x
  
   ```
   brew install python3
   ```
   there are a few alternatives, for instance, you can create a `virtualenv`
   
   ```
   pip3 install virtualenv 
   virtualenv -p python3 <your-venv-path>
   ``` 
  and then activate
  ```
  source <your-venv-path>/bin/activate
  ```
  to deactivate
  ```
  deactivate
  ```
  

#### Other dependencies

- You need Python 3. In most cases, `make deps` will be able to install all additional dependencies:

   ```bash
   make deps
   ```
  
# Prepare your development device

   **Please do not use a Ledger device with funds for development purposes.** 
   
   **Have a second device that is used ONLY for development and testing**

   There are two steps that are useful to increase reproducibility and simplify development:

### Ensure your device works in your OS
- In Linux hosts it might be necessary to adjust udev rules, etc. 

Refer to Ledger documentation: https://support.ledger.com/hc/en-us/articles/115005165269-Fix-connection-issues

### Set test mnemonic

All our tests expect the device to be configured with a known test mnemonic.

- Plug your device while pressing the right button

- Your device will show "Recovery" in the screen

- Double click

- Run `make dev_init`. This will take about 2 minutes. The device will be initialized to:

   ```
   PIN: 5555 
   Mnemonic: equip will roof matter pink blind book anxiety banner elbow sun young
   ```

### Add a development certificate

- Plug your device while pressing the right button

- Your device will show "Recovery" in the screen

- Double click

- Run `make dev_ca`. The device will receive a development certificate to avoid constant manual confirmations.   


# Building the Ledger App

The Makefile will build the firmware in a docker container and leave the binary in the correct directory.

- Build

   The following command will build the app firmware inside a container and load to your device:
   ```
   make                # Builds the app
   ```

- Upload to a device
   The following command will upload the application to the ledger. _Warning: The application will be deleted before uploading._
   ```
   make load          # Builds and loads the app to the device
   ```

# Development (building C++ Code / Tests)

This is useful when you want to make changes to libraries, run unit tests, etc. It will build all common libraries and unit tests.

## Building unit tests
While we recommend you configure your preferred development environment, the minimum steps are as follows: 

   ```
   mkdir build
   cd build
   cmake .. && make
   ```
   **Run unit tests**
   ```
   export GTEST_COLOR=1 && ctest -VV
   ```

## Specifications

- [APDU Protocol](https://github.com/zondax/ledger-polkadot-app/tree/master/docs/APDUSPEC.md)
