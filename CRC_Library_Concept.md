# Digini CRC Library: In-Depth Conceptual Overview

## Introduction
The Digini CRC (Cyclic Redundancy Check) library provides robust and efficient mechanisms for error detection in data transmission and storage. It is designed for embedded systems, offering flexible configuration, high performance, and support for multiple CRC standards.

## Core Concepts

### 1. What is CRC?
CRC is an error-detecting code commonly used to detect accidental changes to raw data. It works by performing polynomial division on the data and appending the remainder (CRC value) to the message. The receiver recalculates the CRC to verify data integrity.

### 2. Supported CRC Standards
The library supports a variety of CRC algorithms, including:
- CRC-8, CRC-16, CRC-32 (common polynomials)
- Custom polynomials (user-defined)
- Configurable initial values, final XOR values, and input/output bit reflection

### 3. Configuration Options
- **Polynomial**: Select from standard or custom polynomials
- **Initial Value**: Set the starting value for CRC calculation
- **Final XOR Value**: Value to XOR with the result before output
- **Input/Output Reflection**: Optionally reverse the bit order of input data and/or CRC result

### 4. Calculation Methods
- **Table-Driven**: Uses precomputed lookup tables for fast CRC calculation, ideal for high-speed applications
- **Bitwise**: Processes data one bit at a time, minimizing memory usage (suitable for resource-constrained systems)
- **Hardware Acceleration**: If available, leverages STM32 CRC hardware peripheral for maximum performance

### 5. API Overview
- `CRC_Calc` class: Encapsulates CRC calculation logic
- `CalculateBuffer()`: One-shot calculation for a data buffer
- `Start()`, `AddBuffer()`, `GetValue()`: For incremental calculation

### 6. Use Cases
- Data integrity verification in communication protocols (UART, SPI, CAN, etc.)
- File and firmware integrity checks
- Memory and storage error detection
- Protocol framing and packet validation

### 7. Performance Considerations
- Table-driven mode is fastest but uses more RAM (for lookup tables)
- Bitwise mode is slower but uses minimal memory
- Hardware mode (if supported) offloads computation from the CPU

### 8. Example Workflow
1. Configure the CRC context (polynomial, initial value, etc.)
2. Initialize the CRC engine
3. Feed data blocks using `AddBuffer()` or `CalculateBuffer()`
4. Retrieve the CRC value with `GetValue()` or directly from `CalculateBuffer()`
5. Compare the calculated CRC with the expected value

### 9. Advanced Features
- **Streaming Support**: Process data in chunks, suitable for large or real-time data streams
- **Custom Polynomials**: Define and use non-standard CRC polynomials for proprietary protocols
- **Endian Handling**: Supports both little-endian and big-endian data formats
- **Test Vectors**: Built-in test functions to validate CRC implementation against known vectors

## Integration with STM32
- Can use STM32's hardware CRC peripheral for supported polynomials
- Fallback to software implementation for unsupported or custom polynomials
- Example code provided for both hardware and software modes

## Best Practices
- Always match CRC parameters (polynomial, initial value, etc.) between sender and receiver
- Use test vectors to validate CRC configuration
- For high-speed or large data, prefer table-driven or hardware-accelerated modes

## Example: Real-World CRC Usage

Below is a real-world example based on the Ethernet MAC address filter use case from the project:

```cpp
#include "lib_crc.h"

// Example: Calculate CRC-32 for a MAC address buffer (as used in Ethernet address filtering)
void example_crc32_mac_address()
{
    uint8_t mac[6] = {0x00, 0x80, 0xE1, 0x00, 0x00, 0x00};
    CRC_Calc myCrc(CRC_32); // Select CRC-32 algorithm
    uint32_t crc = myCrc.CalculateBuffer(mac, 6);
    // Use the CRC value (e.g., for hash table or validation)
}

// Example: Calculate CRC-16-CCITT-FALSE for a data buffer
void example_crc16_ccitt_false()
{
    uint8_t data[] = {0x12, 0x34, 0xAB, 0xCD, 0x00, 0xFF};
    CRC_Calc myCrc(CRC_16_CCITT_FALSE); // Select CRC-16-CCITT-FALSE
    uint16_t crc = (uint16_t)myCrc.CalculateBuffer(data, sizeof(data));
    // Use the CRC value as needed
}
```

**Notes:**
- The `CRC_Calc` class supports many CRC types (CRC_8, CRC_16_CCITT_FALSE, CRC_32, etc.).
- Use the enum value matching your protocol.
- The `CalculateBuffer` method performs the full calculation in one call.
- For incremental calculation, use `Start()`, `AddBuffer()`, and `GetValue()`.

## Conclusion
The Digini CRC library is a versatile and reliable solution for error detection in embedded applications. Its configurability, performance options, and support for industry-standard and custom CRCs make it suitable for a wide range of use cases.

---
*For API details and code examples, refer to the source code and project documentation.*
