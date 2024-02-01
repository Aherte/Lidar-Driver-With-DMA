# Lidar-Driver-With-DMA

 Fully Register based 2d lidar codes without using any IDE or any development environment.

 # Lidar Driver without IDE

This project is a register-based Lidar driver written without using any Integrated Development Environment (IDE). The driver is designed to interface with a Lidar sensor and control it through direct register manipulation. The code is written in C and can be compiled using a suitable toolchain.

## Features

- **Register-based Interaction:** The driver communicates with the Lidar sensor by directly manipulating the hardware registers, providing low-level control over the sensor functionalities.

- **Platform Independence:** The code is intended to be platform-independent, allowing it to be used on various embedded systems without relying on a specific IDE.

- **No External Dependencies:** The driver is designed to be lightweight and does not have external dependencies, making it easy to integrate into different projects.

## Usage

1. Clone the repository:

    ```bash
    git clone https://github.com/your-username/your-lidar-driver.git
    ```

2. Compile the code using your preferred toolchain:

    ```bash
    your-compiler your-lidar-driver/main.c -o lidar_driver
    ```

3. Flash the compiled binary onto your target platform.

4. Execute the binary to run the Lidar driver.

## Contributing

Contributions are welcome! If you would like to contribute to the development of this Lidar driver, please follow the guidelines outlined in the [CONTRIBUTING.md](CONTRIBUTING.md) file.

## License

This project is licensed under the [MIT License](LICENSE), making it open and free for anyone to use and modify.


