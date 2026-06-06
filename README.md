# Nethxeum

Copyright (c) 2024, The Nethxeum Project  
Portions Copyright (c) 2014-2022 The Monero Project  
Portions Copyright (c) 2012-2013 The Cryptonote developers

## Table of Contents

- [Development resources](#development-resources)
- [Vulnerability response](#vulnerability-response)
- [Introduction](#introduction)
- [About this project](#about-this-project)
- [License](#license)
- [Contributing](#contributing)
- [Compiling Nethxeum from source](#compiling-nethxeum-from-source)
- [Using Tor](#using-tor)
- [Debugging](#debugging)
- [Known issues](#known-issues)

## Development resources

- Web: [nethxeum.com](https://nethxeum.com)
- Mail: [contact@nethxeum.com](mailto:contact@nethxeum.com)
- GitHub: [https://github.com/nethxeum/nethxeum](https://github.com/nethxeum/nethxeum)
- Reddit: [r/nethxeum](https://www.reddit.com/r/nethxeum/)

## Vulnerability response

Please open a GitHub issue at [https://github.com/nethxeum/nethxeum/issues](https://github.com/nethxeum/nethxeum/issues) to report any vulnerability or security concern.

## Introduction

Nethxeum (NTU) is a private, secure, untraceable, decentralised digital currency built for private decentralized finance. You are your bank, you control your funds, and nobody can trace your transfers unless you allow them to do so.

**Privacy:** Nethxeum uses a cryptographically sound system to allow you to send and receive funds without your transactions being easily revealed on the blockchain. This ensures that your purchases, receipts, and all transfers remain private by default.

**Security:** Using the power of a distributed peer-to-peer consensus network, every transaction on the network is cryptographically secured. Individual wallets have a 25-word mnemonic seed that is only displayed once and can be written down to backup the wallet. Wallet files should be encrypted with a strong passphrase to ensure they are useless if ever stolen.

**Untraceability:** By taking advantage of ring signatures, RingCT, and stealth addresses, Nethxeum ensures that transactions are not only untraceable but have an optional measure of ambiguity that ensures that transactions cannot easily be tied back to an individual user or computer.

**Block maturity:** Mined outputs require 100 block confirmations before they become spendable, consistent with Bitcoin's approach to coinbase maturity.

**Fair launch:** No premine. No ICO. No founder rewards. Mining started from block 0.

## About this project

This is the core implementation of Nethxeum. It is open source and completely free to use without restrictions, except for those specified in the license agreement below. There are no restrictions on anyone creating an alternative implementation of Nethxeum that uses the protocol and network in a compatible manner.

The `main` branch is the active development branch. For stability, use a tagged release when available. Anyone is welcome to contribute to Nethxeum's codebase via pull requests.

## License

See [LICENSE](LICENSE).

## Contributing

Contributions are welcome. Please submit pull requests to the `main` branch. For significant changes, open an issue first to discuss what you would like to change.

---

## Compiling Nethxeum from source

### Dependencies

The following table summarizes the tools and libraries required to build Nethxeum.

| Dep          | Min. version  | Moniker   | Purpose              |
|--------------|---------------|-----------|----------------------|
| GCC          | 5             | gcc       | C/C++ compiler       |
| CMake        | 3.5           | cmake     | Build system         |
| pkg-config   | any           | pkg-conf  | Library config       |
| Boost        | 1.58          | boost     | C++ libraries        |
| OpenSSL      | basically any | openssl   | sha256 sum           |
| libzmq       | 3.0.0         | zmq       | ZeroMQ library       |
| libunbound   | 1.4.16        | unbound   | DNS resolver         |
| libsodium    | 1.0.7         | libsodium | Cryptography         |
| libunwind    | any           | libunwind | Stack traces         |
| liblzma      | any           | lzma      | For libunwind        |
| libreadline  | 6.3.0         | readline  | Input editing        |
| ldns         | 1.6.17        | ldns      | SSL toolkit          |
| expat        | 1.1           | expat     | XML parsing          |
| GTest        | 1.5           | gtest     | Test suite           |
| Doxygen      | any           | doxygen   | Documentation        |
| Graphviz     | any           | graphviz  | Documentation        |
| libhidapi    | any           | hidapi    | Hardware wallet      |

### Building on Linux

```bash
# Install dependencies (Ubuntu/Debian)
sudo apt install build-essential cmake miniupnpc libunbound-dev graphviz \
  doxygen libunwind8-dev pkg-config libssl-dev libzmq3-dev libsodium-dev \
  libhidapi-dev libnorm-dev libusb-1.0-0-dev libpgm-dev libprotobuf-dev \
  protobuf-compiler libgcrypt20-dev libboost-all-dev

# Clone the repo
git clone --recursive https://github.com/nethxeum/nethxeum.git
cd nethxeum

# Build
make release -j$(nproc)
```

Binaries will be in `build/release/bin/`.

### Building on Windows (MSYS2)

```bash
# Install MSYS2 from https://www.msys2.org/
# Open MSYS2 MinGW 64-bit shell

pacman -S mingw-w64-x86_64-toolchain make mingw-w64-x86_64-cmake \
  mingw-w64-x86_64-boost mingw-w64-x86_64-openssl mingw-w64-x86_64-zeromq \
  mingw-w64-x86_64-libsodium mingw-w64-x86_64-hidapi mingw-w64-x86_64-unbound

git clone --recursive https://github.com/nethxeum/nethxeum.git
cd nethxeum
mkdir build && cd build
cmake .. -G "Unix Makefiles"
make -j$(nproc)
```

### Building on macOS

```bash
brew install cmake pkg-config openssl boost unbound hidapi zmq \
  libpgm libsodium miniupnpc expat libunwind-headers protobuf libgcrypt

git clone --recursive https://github.com/nethxeum/nethxeum.git
cd nethxeum
make release -j$(nproc)
```

---

## Using Tor

Nethxeum can be used with Tor for additional network privacy.

```bash
DNS_PUBLIC=tcp torsocks ./nethxeumd --p2p-bind-ip 127.0.0.1 \
  --rpc-bind-ip 127.0.0.1 --data-dir /path/to/blockchain
```

---

## Debugging

### Stack traces (Unix)

```bash
gdb /path/to/nethxeumd `pidof nethxeumd`
# Then type: thread apply all bt
```

### Memory analysis

```bash
# ASAN
cmake -D SANITIZE=ON -D CMAKE_BUILD_TYPE=Debug ../..

# Valgrind
valgrind /path/to/nethxeumd
```

---

## Known Issues

### Socket-based

- Run `nethxeumd` on a dedicated, secured machine.
- If hosting a public remote node, start with `--restricted-rpc`.

### Blockchain-based

- Received NTU may be locked for a period if the sender set a lock time. Use `show_transfers` to check unlock status.
