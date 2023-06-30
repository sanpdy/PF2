#include "Tree.h"

// Constructor
Tree::Tree() {
    root = NULL;
}

// Destructor
Tree::~Tree() {
    destroyHelper(root);
}

// Recursive function to search for a node with the given title
Book* Tree::search(string title) {
    Node* current = root;
    while (current != NULL) {
        if (current->book.getTitle() == title) {
            return &(current->book);
        }
        else if (title < current->book.getTitle()) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
    return NULL;
}


// Public function to insert a book into the tree
void Tree::insert(Book book) {
    root = insertHelper(root, book);
}

// Private helper function to insert a book into the tree
Node* Tree::insertHelper(Node* node, Book book) {
    if (node == NULL) {
        node = new Node(book);
    } else if (book.getTitle() < node->book.getTitle()) {
        node->left = insertHelper(node->left, book);
    } else if (book.getTitle() > node->book.getTitle()) {
        node->right = insertHelper(node->right, book);
    }
    node = balanceHelper(node);
    return node;
}

// Public function to delete a book from the tree
bool Tree::deleteNode(string title) {
    root = deleteNodeHelper(root, title);
    return (root != NULL); // Return true if root is not null, indicating successful deletion
}


// Private helper function to delete a book from the tree
Node* Tree::deleteNodeHelper(Node* node, string title) {
    if (node == NULL) {
        return NULL;
    } else if (title < node->book.getTitle()) {
        node->left = deleteNodeHelper(node->left, title);
    } else if (title > node->book.getTitle()) {
        node->right = deleteNodeHelper(node->right, title);
    } else {
        if (node->left == NULL && node->right == NULL) {
            delete node;
            node = NULL;
        } else if (node->left == NULL) {
            Node* temp = node;
            node = node->right;
            delete temp;
        } else if (node->right == NULL) {
            Node* temp = node;
            node = node->left;
            delete temp;
        } else {
            Node* temp = findMinHelper(node->right);
            node->book = temp->book;
            node->right = deleteNodeHelper(node->right, temp->book.getTitle());
        }
    }
    if (node != NULL) {
        node = balanceHelper(node);
    }
    return node;
}

// Private helper function to find the minimum node in a subtree
Node* Tree::findMinHelper(Node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Private helper function to get the height of a node
int Tree::getHeightHelper(Node* node) {
    if (node == NULL) {
        return -1;
    }
    return 1 + std::max(getHeightHelper(node->left), getHeightHelper(node->right));
}

// Private helper function to get the balance factor of a node
int Tree::getBalanceHelper(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return getHeightHelper(node->left) - getHeightHelper(node->right);
}

// Private helper function to perform a left rotation
Node* Tree::rotateLeftHelper(Node* node) {
    Node* temp = node->right;
    node->right = temp->left;
    temp->left = node;
    node->height = max(getHeightHelper(node->left), getHeightHelper(node->right)) + 1;
    temp->height = max(getHeightHelper(temp->left), getHeightHelper(temp->right)) + 1;
    return temp;
}

Node* Tree::rotateRightHelper(Node* node) {
    Node* temp = node->left;
    node->left = temp->right;
    temp->right = node;
    node->height = max(getHeightHelper(node->left), getHeightHelper(node->right)) + 1;
    temp->height = max(getHeightHelper(temp->left), getHeightHelper(temp->right)) + 1;
    return temp;
}

Node* Tree::balanceHelper(Node* node) {
    int balanceFactor = getBalanceHelper(node);
    if (balanceFactor > 1) {
        if (getBalanceHelper(node->left) < 0) {
            node->left = rotateLeftHelper(node->left);
        }
        node = rotateRightHelper(node);
    }
    else if (balanceFactor < -1) {
        if (getBalanceHelper(node->right) > 0) {
            node->right = rotateRightHelper(node->right);
        }
        node = rotateLeftHelper(node);
    }

    return node;
}

void Tree::destroyHelper(Node* node) {
    if (node != NULL) {
        destroyHelper(node->left);
        destroyHelper(node->right);
        delete node;
    }
}

void Tree::print() {
    printHelper(root);
}

void Tree::printHelper(Node* node) {
    if (node != NULL) {
        printHelper(node->left);
        cout << node->book.getYear() << ",  ";
        cout << node->book.getTitle() << ",  ";
        cout << node->book.getLastName() << ",  ";
        cout << node->book.getFirstName() << ",  ";
        cout << node->book.getGenre() << ",  ";
        cout << node->book.getRating() << endl;
        printHelper(node->right);
    }
}
// Public function to get the height of the tree
int Tree::getHeight() {
    return getHeightHelper(root);
}

// Public function to get the size of the tree
int Tree::getSize() {
    return getSizeHelper(root);
}

// Private helper function to get the size of a subtree
int Tree::getSizeHelper(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return 1 + getSizeHelper(node->left) + getSizeHelper(node->right);
}



