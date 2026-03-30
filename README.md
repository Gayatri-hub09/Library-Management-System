
# 📚 Library Management System (C++)

A console-based Library Management System developed using **C++** that allows users to manage books efficiently with file handling for persistent storage.

---

## 🚀 Features

* ➕ Add new books
* 📖 View all books
* 🔍 Search books by title
* 📕 Issue books
* 📗 Return books
* 💾 Data persistence using file handling

---

## 🛠️ Tech Stack

* **Language:** C++
* **Concepts Used:** OOP (Classes & Objects)
* **Libraries:** iostream, fstream, vector, string
* **Storage:** File Handling (`books.txt`)

---

## 📂 Project Structure

```
Library-Management-System/
│── main.cpp
│── books.txt
│── README.md
│── .gitignore
```

---

## ⚙️ How to Run

### 1. Clone the repository

```
git clone https://github.com/your-username/Library-Management-System.git
```

### 2. Navigate to project folder

```
cd Library-Management-System
```

### 3. Compile the code

```
g++ main.cpp -o library
```

### 4. Run the program

```
./library
```

---

## 📌 Sample Data Format

Data is stored in `books.txt` in the following format:

```
BookID|Title|Author|Status
```

Example:

```
1|C++ Basics|Bjarne Stroustrup|0
2|Data Structures|Mark Allen Weiss|1
```

* `0` → Available
* `1` → Issued

---

## 🔮 Future Enhancements

* ✅ Input validation
* 🔐 User authentication system
* 🗄️ Database integration (MySQL)
* 🎨 Improved UI/UX
* 🔎 Search by author / ID

---

## 👩‍💻 Author

**Your Name**

* GitHub: [https://github.com/your-username](https://github.com/Gayatri-hub09)

---

## ⭐ Acknowledgment

This project was built as part of learning **C++ programming, file handling, and basic system design concepts**.

---

## 📜 License

This project is open-source and available under the MIT License.
