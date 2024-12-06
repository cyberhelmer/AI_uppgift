# Kontaktbok (Contact Book)

A simple terminal-based contact book application written in C++ with an SQLite backend. This application allows you to:
- Add new contacts with a name, email, and phone number.
- View all saved contacts.
- Search for contacts by name or phone number.

---

## Features
1. **Add Contacts**: Save a contact with multiple fields (name, email, phone number).
2. **View Contacts**: Display a list of all saved contacts.
3. **Search Contacts**: Search contacts by name or phone number.
4. **SQLite Backend**: Data is stored persistently in an SQLite database.

---

## Prerequisites

Before running the application, ensure the following are installed on your system:

1. **C++ Compiler** (e.g., `g++`, `clang`):
   - On Ubuntu/Debian:
     ```
     sudo apt install build-essential
     ```
   - On macOS:
     Comes pre-installed with Xcode Command Line Tools.

2. **SQLite3 Development Library**:
   - On Ubuntu/Debian:
     ```
     sudo apt install libsqlite3-dev
     ```
   - On macOS:
     ```
     brew install sqlite
     ```

3. **CMake** (Optional, for automated builds):
   - Install via your package manager:
     - On Ubuntu/Debian:
       ```
       sudo apt install cmake
       ```
     - On macOS:
       ```
       brew install cmake
       ```

---

## Setup and Usage

### 1. Clone the Repository
git clone https://github.com/your-username/kontaktbok.git cd kontaktbok

### 2. Build the Project

#### Using CMake:
mkdir build cd build cmake .. make

#### Directly Using g++:
If you don’t want to use CMake, compile directly using:
g++ -std=c++17 main.cpp contact.cpp database.cpp -o kontaktbok -lsqlite3

### 3. Run the Application
After building, run the executable:



---

## Example Usage

1. **Add a Contact**:
   - Enter `1` in the menu to add a new contact.
   - Provide the name, email, and phone number when prompted.

2. **View All Contacts**:
   - Enter `2` to see all saved contacts.

3. **Search for a Contact**:
   - Enter `3` and type a name or phone number to search.

4. **Exit**:
   - Enter `4` to exit the application.

---


---

## Dependencies
- **SQLite3**: Used for persistent storage of contacts.
- **Standard Library**: The project uses C++17 features such as `std::vector` and `std::string`.

---

## Contributing
Contributions are welcome! Feel free to submit issues or pull requests for bug fixes or enhancements.

---

## License
This project is licensed under the MIT License. See the `LICENSE` file for more details.

---

## Contact
For any questions or issues, feel free to reach out:
- **Email**: your-email@example.com
- **GitHub**: [your-username](https://github.com/your-username)

---

### Enjoy using your terminal-based contact book! 🎉
