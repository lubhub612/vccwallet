VccWallet is a z-Addr compatible wallet and full node for vcoind that runs on Linux, Windows.


# Installation

Head over to the releases page and grab the latest installers or binary. https://github.com/lubhub612/vccwallet/releases

### Linux

If you are on Debian/Ubuntu.
```

```

you can download and run the binaries directly.
```
tar -xvf vccwallet-v0.0.1.tar.gz
./vccwallet-v0.0.1/vccwallet
```

### Windows
You can download the release binary, unzip it and double click on `vccwallet.exe` to start.



## vcoind
VccWallet needs a Vcoin node running vcoind. If you already have a vcoind node running, VccWallet will connect to it. 

If you don't have one, VccWallet will start its embedded vcoind node. 

Additionally, if this is the first time you're running VccWallet or a vcoind daemon, VccWallet will download the Vcoin params (~1.77 GB) and configure `vcoin.conf` for you. 

Pass `--no-embedded` to disable the embedded vcoind and force VccWallet to connect to an external node.

## Compiling from source
VccWallet is written in C++ 14, and can be compiled with g++/clang++/visual c++. It also depends on Qt5, which you can get from [here](https://www.qt.io/download). Note that if you are compiling from source, you won't get the embedded vcoind by default. You can either run an external vcoind, or compile vcoind as well. 

See detailed build instructions [on the wiki](https://github.com/lubhub612/vccwallet/wiki/Compiling-from-source-code)

### Building on Linux

```
git clone https://github.com/lubhub612/vccwallet.git
cd vccwallet
/path/to/qt5/bin/qmake vcc-qt-wallet.pro CONFIG+=debug
make -j$(nproc)

./vccwallet
```

```

### [Instruction]
Please disable your antivirus before downloding the zip file and allow the firewall while installing...
