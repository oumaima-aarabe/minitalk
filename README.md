# Minitalk

## Introduction
Welcome to the Minitalk project! This project implements a simple client-server communication system using signals in Unix. The goal is to establish communication between a client and server processes, allowing the client to send a string message to the server.

## Description
Minitalk utilizes Unix signals to establish communication between a client and server process. The client sends a string message to the server by converting each character into a series of binary digits and transmitting them as signals. The server receives these signals, decodes them, and reconstructs the original message.

## Features
- **Client-Server Communication**: Minitalk facilitates communication between a client and server process running on the same machine.
- **Signal Handling**: The project demonstrates how to handle signals in Unix, specifically `SIGUSR1` and `SIGUSR2`, for communication purposes.
- **Message Encoding and Decoding**: Characters are encoded into binary format before being transmitted as signals. The server decodes the received signals to reconstruct the original message.

## Getting Started
To run Minitalk on your local machine, follow these steps:

### Prerequisites
Ensure you have the following installed:
- C Compiler (e.g., GCC)

### Installation
1. Clone this repository to your local machine:
   ```bash
   git clone https://github.com/your_username/minitalk.git

2.Compile the source code using the Makefile

## Usage
1. Start the server:
   ```bash
   ./server
The server will display its process ID (PID) upon initialization.

2. Start the client:
   ```bash
   ./client [server_pid]

Replace [server_pid] with the PID of the server process displayed in step 1.
 Once the client is started, you can keep sending messages to the server using the client prompt.
  
