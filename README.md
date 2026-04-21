# Zyengine

High performance Discord Gateway infrastructure utilizing a Go network bridge and a C++ rate limiting core. This system is designed for extreme low-latency event 


## Features

 * **IPC First Architecture**: Utilizes Unix Domain Sockets (AF_UNIX) for zero latency communication between services.

 * **Atomic Rate Limiting**: C++ core utilizes lock free atomic operations (compare_exchange_weak) for high concurrency state management.

 * **Multi Language Interop**: Seamlessly bridges Go (Networking), C++ (Engine), and Python/JS (Workers).


## Directory Structure

 * engine/: Core C++ processing logic and rate limiting system.

 * Infra/: Go-based Discord Gateway bridge and TLS handle3rs.

 * include/: Shared protocol headers and IPC packet definitions.

 * workers/: Example consumer implementations in Python and Node.js.


## Build Instructions

 1. **Permissions**:
   chmod +x build.sh

 2. **Compile**:
   ./build.sh (Requires g++, golang, and make)


## Usage
 1. **Start the Core Engine**:
   ./engine_bin
 2. **Initialize the Gateway Bridge**:
   ./infra_bin
 3. **Launch a Worker**:
   python3 workers/python/worker.py


> **Note**: This project is maintained by **Zykov**, organization's security and automation toolset. Use responsibly and within the scope of Discord's Developer Terms of Service.
