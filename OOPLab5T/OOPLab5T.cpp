#include <iostream>
using namespace std;

/*Створити клас Pair (пара чисел); визначити методи зміни полів і ви-числения
твори чисел. Визначити похідний клас Rectangle (прямокутник) з полями-сторонами.
Визначити методи обчислення периметра і площі прямокутника*/
 /*
// Базовий клас Pair (пара чисел)
class Pair {
protected:
    int first, second; // Поля для зберігання двох чисел

public:
    Pair(int f, int s) : first(f), second(s) {} // Конструктор для ініціалізації чисел

    // Методи для зміни чисел
    void setFirst(int f) { first = f; }
    void setSecond(int s) { second = s; }

    // Методи для отримання чисел
    int getFirst() const { return first; }
    int getSecond() const { return second; }

    // Метод для обчислення суми чисел
    int sum() const { return first + second; }
};

// Похідний клас Rectangle (прямокутник)
class Rectangle : public Pair {
public:
    Rectangle(int length, int width) : Pair(length, width) {} // Конструктор прямокутника зі сторонами

    // Метод для обчислення периметра прямокутника
    int perimeter() const { return 2 * (first + second); }

    // Метод для обчислення площі прямокутника
    int area() const { return first * second; }
};

int main() {
    Rectangle rect(5, 3); // Створення об'єкту прямокутника зі сторонами 5 та 3

    // Виведення периметру та площі прямокутника
    cout << "Rectangle perimeter: " << rect.perimeter() << endl;
    cout << "Rectangle area: " << rect.area() << endl;

    return 0;
}
     */
/*Використовуючи ієрархію й композицію класів, створити бінарне дерево.У
бінарного дерева є кореневий вузол. Ми можемо вставляти вузол. Ми можемо
обходити завширшки.*/

#include <iostream>
#include <queue>
using namespace std;

// Клас, що представляє вузол бінарного дерева
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    // Конструктор за замовчуванням
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Клас для представлення бінарного дерева
class BinaryTree {
private:
    TreeNode* root;

public:
    // Конструктор за замовчуванням
    BinaryTree() : root(nullptr) {}

    // Метод для вставки вузла в дерево
    void insertNode(int val) {
        TreeNode* newNode = new TreeNode(val);
        if (root == nullptr) {
            root = newNode;
            cout << "Inserted " << val << " as the root node" << endl;
            return;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if (current->left == nullptr) {
                current->left = newNode;
                cout << "Inserted " << val << " as the left child of " << current->data << endl;
                break;
            }
            else {
                q.push(current->left);
            }

            if (current->right == nullptr) {
                current->right = newNode;
                cout << "Inserted " << val << " as the right child of " << current->data << endl;
                break;
            }
            else {
                q.push(current->right);
            }
        }
    }

    // Метод для обходу дерева в ширину
    void breadthFirstTraversal() {
        if (root == nullptr) {
            cout << "Tree is empty" << endl;
            return;
        }

        queue<TreeNode*> q;
        q.push(root);

        cout << "Breadth First Traversal: ";
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
        cout << endl;
    }
};

int main() {
    BinaryTree tree;
    tree.insertNode(1);
    tree.insertNode(2);
    tree.insertNode(3);
    tree.insertNode(4);
    tree.insertNode(5);
    tree.breadthFirstTraversal();

    return 0;
}
