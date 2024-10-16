# TCP KINK SERVER

## Overview

The TCP Kink Server is a simple TCP client that connects to a specified server

## Installation

```
mkdir tcp-server
cd tcp-server
git clone git@github.com:Fateskink/tcp-server-kink.git
```

## Compile:
```
make
```

## Run
```
./tcp
```

## Code Explanation
- Socket Creation: Creates a TCP socket.
- Setup Address: Configures the server's IP and port.
- Connect: Establishes a connection to the server.
- Send Request: Sends the HTTP HEAD request.
- Receive Response: Reads and prints the server's response.
