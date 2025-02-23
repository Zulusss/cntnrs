#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <memory>
#include <sstream>
// using namespace std;

static const std::string ch_hor = "-";
static const std::string ch_ver = "|";
static const std::string ch_ddia = "/";
static const std::string ch_rddia = "\\";
static const std::string ch_udia = "\\";
static const std::string ch_ver_hor = "|-";
static const std::string ch_udia_hor = "\\-";
static const std::string ch_ddia_hor = "/-";
static const std::string ch_ver_spa = "| ";

template<typename T>
class AVLTree {
        using reference = T &;
        using const_reference = const T &;
        //using iterator = My_Iterator;
        using const_iterator = const T *;
        using size_type = size_t;
        // using itrt = T *;
        using key_type = T;
        using value_type = T;
        // using iterator = T *;
public:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node* prev;
        Node* next;
        
        int height;

        Node(T value) : data(value), left(nullptr), right(nullptr), prev(nullptr), next(nullptr), height(1) {}
    };
    // int num;
    
    class My_Iterator {
        public:
        
        My_Iterator() : currentNode(nullptr) {}

        My_Iterator(Node* startNode) : currentNode(startNode) {
            // Node* My_Node = startNode;
            // linkNodes_backward(My_Node);
        }

        My_Iterator(AVLTree<T>& tree, size_t position) {
            // Используем метод дерева для инициализации currentNode
            currentNode = tree.findKthNode(tree.root, position);
        }

        My_Iterator(int number) : My_Iterator{currentNode} {
            // linkNodes(currentNode);
            // currentNode->height = num;
            // num = number;
            // linkNodes(currentNode);
            // linkin_park(currentNode);
            // if(currentNode->prev)   currentNode   =  currentNode->prev;
            // this = *root;
            // if(!currentNode) std::cout << "no" << std::endl;
            // else
            // while(currentNode->prev) currentNode = currentNode->prev;
            // currentNode = findKthNode();
            // root.finder(num);
            // My_Iterator it = begin();
            // currentNode->
            // currentNode = root;
            // position = num;
            // finder(num, currentNode);
            // currentNode = findKthNode(root, num);
            // currentNode = res; 
        }
        
        bool hasNext() {
            // return currentNode->next ? true : false;
            return !parentStack.empty();
        }

        // void erase(){

        // }

        T& operator*() const {
            return currentNode->data;
        }
        My_Iterator& operator--(int) {
            if(currentNode->prev) return *this = currentNode->prev;
            else return *this;
          }

          My_Iterator& operator--() {
            // Node* ret = currentNode->prev ? currentNode->prev : currentNode;
            // Node* ret = nullptr;
            if(currentNode->prev)
            return *this = currentNode->prev;
            else return *this;
          }

        My_Iterator& operator++(int) {
            if(currentNode->next) return *this = currentNode->next;
            else return *this;
          }

        My_Iterator& operator++() {
            
            Node* ret = nullptr;
            if(currentNode->next) return *this = currentNode->next;
            else return *this;

            do {
            
                if(is_down && currentNode->left){
                    is_down = true;
                    is_right = false;
                    ret = currentNode;
                    parentStack.push(currentNode);
                    currentNode = currentNode->left;}

                else if(!is_down && currentNode->right){
                    is_down = true;
                    is_right = true;
                    ret = currentNode;
                    parentStack.push(currentNode);
                    ret = currentNode = currentNode->right;}
                else {
                    if (is_down) {
                        is_down = false;
                        // if(!is_right)                    
                        ret = currentNode;
                        std::cout << ret->data << " from first time ++ " << std::endl;
                        // if(ret. )
                        // ret = nodeStack.top();
                        // else std::cout << "empty stack" << std::endl;
                        // std::cout << ret->data << " from stack ++ " << std::endl;
                    }
                    else {
                        std::cout << currentNode->data << " ret" << std::endl;
                        currentNode = parentStack.top();
                        parentStack.pop();
                    }
                  }
                  std::cout << currentNode->data << " Another after do" << std::endl;
                    
            } while(is_down || is_right);
            std::cout << ret->data << " before return from ++ " << std::endl;
            this->currentNode = ret;
            
            // return ret;
            return *this;

            // if (!currentNode) {
            //     throw std::out_of_range("Iterator out of range");
            // }
            // currentNode = currentNode->next;
            // return *this;
        }

        bool operator!=(const My_Iterator& other) const {
            return currentNode != other.currentNode;
        }

    public:
        Node* currentNode = root;
        // Node* start = root.begin();
        std::stack<Node*> parentStack;
        bool is_down = true;
        bool is_right = false;
        // size_t position = 0;
    };

    class HateCrewIterator{

    };
    // Iterator Begin() {

    //     // if (!root) return Iterator(nullptr);
    //     // Node* start = root;
    //     // while (start->left) {
    //     //     start = start->left;
    //     // }
    //     // linkNodes(root);
    //     Iterator ret = Iterator(root);
    //     ++ret;
    //     return ret;
    // }

    // Iterator End() {
    //     return Iterator(nullptr);
    // }

    void linkNodes(Node* node) {
        static Node* lastVisited = nullptr;
        if (!node) return;
        linkNodes(node->left);
        if (lastVisited) {
            lastVisited->next = node;
        }
        lastVisited = node;
        linkNodes(node->right);
    }

    void linkNodes_backward(Node* node) {
        static Node* lastVisited = nullptr;
        if (!node) return;
        linkNodes_backward(node->right);
        if (lastVisited) {
            lastVisited->prev = node;
        }
        lastVisited = node;
        linkNodes_backward(node->left);
    }

    void linkin_park(){
        linkNodes(root);
        linkNodes_backward(root);
    }

    size_t how_much = 0;
    bool contact{false};
    
// template<typename T>
class Visitor {
public:
    virtual void visit(const T& value) = 0;
    virtual void setSteps(int steps) { this->steps = steps; }
// protected:
    int steps = 0;
    virtual int getSteps(){return steps;}
};
    // friend void Visitor::accept(Visitor& visiter, int steps=0);

    class NewIdeaIterator {
    // friend class AVLTree<T>;
    public:
    Node* current;
    NewIdeaIterator() : current(nullptr) {}
    NewIdeaIterator(Node* node) : current(node) {}
    

    T& operator*() {
        return current->data;
    }

        reference operator*() const {
            if(current) return current->data;
            throw std::runtime_error("Dereferencing a null iterator");

        }
    };

    class SetIterator {
    public:
        SetIterator(Node* root) {
            pushLeft(root);
        }
    
        bool hasNext() {
            return !nodeStack.empty();
        }
    
        T next() {
            if (!hasNext()) {
                throw std::out_of_range("No more elements in the iterator");
            }
    
            Node* currentNode = nodeStack.top();
            nodeStack.pop();
            pushLeft(currentNode->right);
            return currentNode->data;
        }

        Node* stop_pushing(size_t stop){
            Node* result = nodeStack.top();
            while(stop--)
            nodeStack.pop();
            if(hasNext())
            result = nodeStack.top();
            return result;
        }

        SetIterator Iterator_pos(size_t cnt_inside=0){
            cnt = cnt_inside;
            pushLeft(root);
            Node* currentNode = nodeStack.top();
            while(cnt--){
                nodeStack.pop();
                currentNode = nodeStack.top();
            }
            return currentNode;
        }
    
    private:
        std::stack<Node*> nodeStack;
        size_t cnt = 0;
        void pushLeft(Node* node) {
            while (node) {
                cnt++;
                nodeStack.push(node);
                node = node->left;
            }
        }
    };

    My_Iterator begin(){
        linkNodes(root);
        linkNodes_backward(root);
        // while()

        Node* ret = findmin(root);
        return My_Iterator(ret);
    };

    My_Iterator end(){
        linkNodes(root);
        linkNodes_backward(root);
        Node* ret = findmax(root);
        return My_Iterator(ret);
    }


    My_Iterator find(const key_type key){
  
        Node* comeback;
        // My_Iterator ret;
     
        bool res = this ->contains(key);
        if(res){
        
        comeback = SuperFind(root, key);
        My_Iterator ret { comeback};
        return ret;
        // return comeback;
        } //else how_much--;

        return end();
    }

    AVLTree& operator=(const AVLTree &other){
        if(this != &other){
        AVLTree tmp;
        clear(root);
        *this = std::move(tmp);
        }
        return *this;
    }

    Node* root;
        
    AVLTree() : root(nullptr) {}

    AVLTree(std::initializer_list<value_type> const &items) : root(nullptr) {
    
    for (auto it = items.begin(); it != items.end(); it++) {
        auto tmp = *it;
        insert(tmp);
        }
    };

    ~AVLTree() {
        clear(root);
    }

    AVLTree(AVLTree &other) noexcept {
        this->root = xerox(other.root);
    }

    void clear(Node* node) {    //post-order л-п-к
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    Node* xerox(Node* node){    //pre-order к-л-п

        if(!node) return nullptr;
            else {
            Node * for_copy = new Node(node->data);
            for_copy->left = xerox(node->left);
            for_copy->right = xerox(node->right);
            return for_copy;
        }    
    }

    bool contains(const key_type& key){
        if(!root) return false;
        if (how_much == 1 && root->data == key) return true;

        Node* comeback;

        comeback = SuperFind(root, key);
        if(comeback->data == maxdata() ) { return false;}
        else return true;
    }

    std::pair<My_Iterator, bool> insert(const value_type& value){
        Node* get_over_here;
        if(contains(value)) {get_over_here = SuperFind(root, value); My_Iterator ret{get_over_here}; return std::make_pair(ret, false);}
        else {root = insert(root, value); get_over_here = SuperFind(root, value); My_Iterator ret{get_over_here}; return std::make_pair(get_over_here, true);} 
    }

    void erase(int num){
        int cnt = 0;
        if(!contact)  cnt = 1;
        
        Node* victim =  findKthNode(root,  num);
        std::cout << victim->data << " victim "  <<  std::endl;
        root = remove(root, victim->data);
        cnt++;  

    }

    Node* SuperFind(Node* node, T value) {

        if (!node) return findmax(root);
        if(node->data == value) return node;

        if (value < node->data) {
            return SuperFind(node->left, value);
        } else if (value > node->data) {
            return SuperFind(node->right, value);
        } else
             return node; // Дубликаты не разрешены contact{true};
         
    }

    bool empty(){
        return root == nullptr;
    }

    int height(Node* node) {
        return node ? node->height : 0;
    }

    int balanceFactor(Node* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    void updateHeight(Node* node) {
        if (node) {
            node->height = 1 + std::max(height(node->left), height(node->right));
        }
    }

    Node* rightRotate(Node* y) {    //counterclockwise around y, now it is right
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);
        return y;
    }

    Node* insert(Node* node, T value) {    //in-order л-п-к
        if (!node) {how_much++; return new Node(value);}

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        } else {
             return node; // Дубликаты не разрешены contact{true};
        }

        updateHeight(node);

        int balance = balanceFactor(node);

        

        if (balance < -1 && value > node->right->data) {
            return leftRotate(node);
        }

        // Левый правый случай
        if (balance > 1 && value > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Правый левый случай
        if (balance < -1 && value < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node* Balance(Node* node) {

        updateHeight(node);
        int balance = balanceFactor(node);
        T value = node->data;         

        // Левый левый случай
        if (balance > 1 && value < node->left->data) {
            return rightRotate(node);
        }
        // Правый правый случай
        if (balance < -1 && value > node->right->data) {
            return leftRotate(node);
        }
        // Левый правый случай
        if (balance > 1 && value > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Правый левый случай
        if (balance < -1 && value < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // void insert(T value) {
    //     root = insert(root, value);
    // }

    void inOrder(Node* node) {
        if (node) {
            inOrder(node->left);
            std::cout << node->data << " ";
            inOrder(node->right);
        }
    }

    void print() {
        inOrder(root);
        std::cout << std::endl;
    }

void dump0(Node* node, std::string const & prefix = "", bool root = true, bool last = true) {
    std::cout << prefix << (root ? "" : (last ? ch_udia_hor : ch_ver_hor)) << (node ? std::to_string(node->data) : "") << std::endl;
    if (!node || (!node->left && !node->right))
        return;
    std::vector<Node *> v{node->left, node->right};
    for (size_t i = 0; i < v.size(); ++i)
        dump0(v[i], prefix + (root ? "" : (last ? "  " : ch_ver_spa)), false, i + 1 >= v.size());
}

void dump2(Node * node, std::string const & rpref = "", std::string const & cpref = "", std::string const & lpref = "") {
    if (!node) return;
    if (node->right)
        dump2(node->right, rpref + "  ", rpref + ch_ddia_hor, rpref + ch_ver_spa);
    std::cout << cpref << std::to_string(node->data) << std::endl;
    if (node->left)
        dump2(node->left, lpref + ch_ver_spa, lpref + ch_udia_hor, lpref + "  ");
}

void dump4(Node * node, bool high = true, std::vector<std::string> const & lpref = std::vector<std::string>(), std::vector<std::string> const & cpref = std::vector<std::string>(), std::vector<std::string> const & rpref = std::vector<std::string>(), bool root = true, bool left = true, std::shared_ptr<std::vector<std::vector<std::string>>> lines = nullptr) {
    if (!node) return;
    typedef std::vector<std::string> VS;
    auto VSCat = [](VS const & a, VS const & b){ auto r = a; r.insert(r.end(), b.begin(), b.end()); return r; };
    if (root) lines = std::make_shared<std::vector<VS>>();
    
    if (node->left)
        dump4(node->left, high, VSCat(lpref, high ? VS({" ", " "}) : VS({" "})), VSCat(lpref, high ? VS({ch_ddia, ch_ver}) : VS({ch_ddia})), VSCat(lpref, high ? VS({ch_hor, " "}) : VS({ch_hor})), false, true, lines);
    
    std::ostringstream oss;
    oss << node->data;
    std::string sval = oss.str();
    
    size_t sm = left || sval.empty() ? sval.size() / 2 : ((sval.size() + 1) / 2 - 1);
    for (size_t i = 0; i < sval.size(); ++i)
        lines->push_back(VSCat(i < sm ? lpref : i == sm ? cpref : rpref, {std::string(1, sval[i])}));
    
    if (node->right)
        dump4(node->right, high, VSCat(rpref, high ? VS({ch_hor, " "}) : VS({ch_hor})), VSCat(rpref, high ? VS({ch_rddia, ch_ver}) : VS({ch_rddia})), VSCat(rpref, high ? VS({" ", " "}) : VS({" "})), false, false, lines);
    
    if (root) {
        VS out;
        for (size_t l = 0;;++l) {
            bool last = true;
            std::string line;
            for (size_t i = 0; i < lines->size(); ++i)
                if (l < (*lines).at(i).size()) {
                    line += lines->at(i)[l];
                    last = false;
                } else line += " ";
            if (last) break;
            out.push_back(line);
        }
        for (size_t i = 0; i < out.size(); ++i)
            std::cout << out[i] << std::endl;
    }
}

Node * findmin(Node* node){
    return node->left ? findmin(node->left) : node;
}

Node * findmax(Node* node){
    return node->right ? findmax(node->right) : node;
}

Node* RemoveMin(Node* node){
    if(!node->left)
        return node->right;
    node->left = RemoveMin(node->left);
    return Balance(node);
}

Node* remove(Node* node, T data){
    if(!node) return 0;
    if(data < node->data)
        node->left = remove(node->left, data);
    else if(data > node->data)
        node->right = remove(node->right, data);
    else{
        how_much--;
        Node* left = node->left;
        Node* right = node->right;
        delete node;
        if(!right) return left;
        Node* min = findmin(right);
        min->right = RemoveMin(right);
        min->left = left;
        return Balance(min);
    }
    return Balance(node);
}

T mindata(){
    return findmin(root) ->data;
}

T maxdata(){
    return findmax(root)->data;
}

T getData(Node* node){
    return node->data;
}

size_type size(){
    return how_much;
}

void tired(Node* cunt, int c){
    Node* scott = findKthNode(root, c);
}

void inorder(Node* root, int& counter, int k, Node*& target) {
    if (root == nullptr || target != nullptr) return;

    inorder(root->left, counter, k, target);
    if (++counter == k) {
        target = root;
        return;
    }
    inorder(root->right, counter, k, target);
}

Node* findKthNode(Node* root, int k) {
    Node* target = nullptr;
    int counter = 0;
    inorder(root, counter, k, target);
    return target;
}

void finder(size_t num){
    Node* res;
    res = findKthNode(root, num);
    My_Iterator ret{res};
}

// void erase(My_Iterator pos){
//     // pos = My_Iterator::position;
//     if(pos < 1 || pos > how_much) std::cout << " Out of index " << std::endl;
//     else{
//         Node* victim = findKthNode(root, pos);
//         root = remove(root, victim->data); 
//     }
// }
void erase(My_Iterator pos) {
    // if(number) std::cout << " This is it " << std::endl;
    if (pos.currentNode == nullptr) {
        std::cout << "Iterator is null, cannot erase." << std::endl;
        return;
    }

    // Получаем данные узла, который нужно удалить
    T valueToRemove = pos.currentNode->data;

    // Удаляем узел из дерева
    root = remove(root, valueToRemove);
}

// void erase(My_Iterator pos) {
//     My_Iterator tmp{root};
//     if(tmp!=pos){ 
//     tmp++;} std::cout << "*tmp   " << *tmp << std::endl;
    
//     // remove(pos.currentNode, pos.currentNode->data);
//     // Получаем позицию из итератора
//     // My_Iterator   pos = nullptr;
//     // size_t index = findIndex(pos);
    
//     // if (index < 1 || index > how_much) {
//     //     std::cout << " Out of index " << std::endl;
//     // } else {
//     //     Node* victim = findKthNode(root, index);
//     //     root = remove(root, victim->data); 
//     // }
// }

// Метод для нахождения индекса из итератора
size_t findIndex(My_Iterator pos) {
    // pos = nullptr;
    // My_Iterator pos = root->begin();
    size_t index = 1; // Начинаем с 1, если вы используете 1-индексацию
    for (auto it = begin(); it != end(); ++it) {
        ++index;
        // if (pos.hasNext)  {++index;}// return index;
        std::cout << "index++" << index << "pos" << *pos <<std::endl;
    }
    return index;
}


    void accept(Visitor& visitor, int steps=0) {
        if(steps == 0) steps = how_much;
        visitor.setSteps(steps);
        inOrderTraversal(root, visitor);
    }
    
    void inOrderTraversal(Node* node, Visitor& visitor) {
        if (node && visitor.steps > 0) {
            inOrderTraversal(node->left, visitor); // Visit left subtree
            if(--visitor.steps == 0){
            visitor.visit(node->data);              // Visit current node
            }
            inOrderTraversal(node->right, visitor); // Visit right subtree
        }
    }
};

template<typename T>
class PrintVisitor : public AVLTree<T>::Visitor
 {
    public:
        int sum = 0;
        // int getSteps() override {return steps;}
        void visit(const T& value) override {
            std::cout << value << " ";
            sum += value;
            // if(0 == getSteps()) std::cout << sum << " ";
            std::cout << sum << " ";
        }
};

int main() {
    // AVLTree<std::string> tree;
    // tree.insert("a");
    // tree.insert("b");
    // tree.insert("c");
    // tree.insert("d");
    // tree.insert("e");
    // tree.insert("f");
    // tree.insert("g");

    AVLTree<int> oak = {99, 33, 55, 44};
    oak.dump4(oak.root);
    std::cout << "Lets try auto way " << std::endl;
    for(auto i: oak) std::cout << i <<  " "  << std::endl;
    std::cout << " This is it? " << std::endl;
    AVLTree<int> pinus;
        for (size_t i = 1; i < 490; i+=10)
    {
        // /* code */tree2.insert(rand() % 1000);
        pinus.insert(i);
        // origin.insert(i);
        // origin.insert(rand() % 1000);
    }
    // tree.erase(3)
    // IntPrintVisitor guest;
    // AVLTree<int>::Iterator iter; 
    // AVLTree<int>::Iterator iter2(oak.root);
    //AVLTree<int>::iterator Roman;
    auto Roman = oak.begin();
    // for(auto i: oak)
    // std::cout << i << std::endl;
    // ++Roman;
    
    std::cout << *Roman << "   Roman   " <<std::endl;
    ++Roman;
    std::cout << *Roman << "   Roman   " <<std::endl;
    ++Roman;
    std::cout << *Roman << "   Roman   " <<std::endl;
    ++Roman;
    std::cout << *Roman << "   Roman   " <<std::endl;
    --Roman;
    std::cout << *Roman << "   Roman   " <<std::endl;
    --Roman;
    std::cout << *Roman << "   Roman   " <<std::endl;
    --Roman;
    std::cout << *Roman << "   Roman   " <<std::endl;

    auto not_Roman = pinus.end();
    std::cout << *not_Roman << "     not_Roman" << std::endl;

    --not_Roman;
    std::cout << *not_Roman << "     not_Roman" << std::endl;
    for(auto narcoMan = pinus.begin(); narcoMan != pinus.end(); narcoMan++)
        {std::cout << *narcoMan << std::endl;}
    
        for(auto narcoMan2 = pinus.end(); narcoMan2 != pinus.begin(); narcoMan2--)
        {std::cout << *narcoMan2 << std::endl;}
    
      
    // PrintVisitor<int> guest;
 
    // //std::string end_of_binarytree_strings = tree.maxdata();
    // //std::cout << "  end of strings   " << end_of_binarytree_strings << std::endl;
    std::cout<< std::endl;
    

    // for(size_t i = 1; i <= oak.size(); i++){
    //     oak.accept(guest, i);
    // }

    // // tree.accept(printVisitor); // Используем посетителя для обхода дерева
    // std::cout<< std::endl;
    // int finish = oak.maxdata();


    // std::cout<< finish << "   last " << std::endl;

    // oak.dump4(oak.root);
    //tree.dump4(tree.root);
    //tree.print();
    // std::cout << std::endl;

    // AVLTree<int> tree2;
    // AVLTree<int> pinus = {3, 4, 5, 3, -999, 111};
    // // std::set<std::string> origin;
    // std::set<int> origin;
    // for (size_t i = 1; i < 49; i++)
    // {
    //     // /* code */tree2.insert(rand() % 1000);
    //     tree2.insert(i);
    //     origin.insert(i);
    //     // origin.insert(rand() % 1000);
    // }
    // std::cout << origin.size() << "   original size    "  << std::endl;
    // std::cout << tree2.size() << "    size    "  << std::endl;
    // // tree2.dump4(tree2.root);
    // std::cout << " min " << tree2.mindata() <<  std::endl; 
    // std::cout << " empty? " << tree2.empty() <<  std::endl; 
    // AVLTree<int>::SetIterator it(tree2.root);
    // while (it.hasNext()) {
    //     std::cout << it.next() << " ";
    // }
    // std::cout << endl;
    // AVLTree<int>::NewIdeaIterator fck(tree2.root); // Correct initialization


    // std::set<int>::iterator original;
    
    AVLTree<int>::My_Iterator fck;
    fck = pinus.findmin(pinus.root);
    std::cout << *fck << "  min  " << std::endl;
    fck = pinus.findmax(pinus.root);
    std::cout << *fck << "  max  " << std::endl;
    // AVLTree<int>::NewIdeaIterator tst;
    // tst = tree2.begin();
    // std::cout << *tst << "  begin ura!!! it works!!! " << std::endl;
    // tst = tree2.end();
    // std::cout << *tst << "  end it works!!! " << std::endl;
    // // size_type r;
    // // std::cout << fck
    // std::cout << *original << "  begin  " << std::endl;
    // original = origin.end();
    // std::cout << *original << "  end  " << std::endl;

    std::cout << pinus.size() << "  size    " << std::endl;
    // std::cout << origin.size() << "   original size    " << std::endl;
    // // AVLTree<int> copy_tree_init  = {3,4,5};
    // // copy_tree_init.dump4(copy_tree_init.root);
    // // copy_tree = tree2;
    // // std::cout << copy_tree.size() << " copy_size    " << std::endl;

    // // tree2.dump4(tree2.root);

    fck = pinus.find(0);
    std::cout << *fck << "  find 0  " << std::endl;
    fck = pinus.find(1);
    std::cout << *fck << "  find 1  " << std::endl;
    ++fck;
    std::cout << *fck << "  ++  " << std::endl;
    bool res = pinus.contains(555);
    std::cout  << res << "     contains  555" << std::endl;
    res = pinus.contains(5);
    std::cout  << res << "     contains  5" << std::endl;
    
    // pinus.erase(pinus.begin());
    pinus.erase(5);
    pinus.print();
    pinus.erase(5);
    pinus.dump4(pinus.root);
    // oak.dump4(oak.root);

    // // tree2.dump4(tree2.root);
    // auto resa = origin.insert(3);
    // std::cout << "Origin: " << *resa.first << ", True: " << resa.second << std::endl;
    // auto resa2 = tree2.insert(3);
    // std::cout << "My: " << *resa2.first << ", True: " << resa2.second << std::endl;
    // std::cout << tree2.size() << "  size    " << std::endl;
    // std::cout << origin.size() << "   original size    " << std::endl;

    // resa = origin.insert(333);
    // std::cout << "Origin2: " << *resa.first << ", True: " << resa.second << std::endl;
    // resa2 = tree2.insert(333);
    // std::cout << "My2: " << *resa2.first << ", True: " << resa2.second << std::endl;
    
    // std::cout << tree2.size() << "    size    "  << std::endl;
    // std::cout << origin.size() << "   original size    "  << std::endl;

    // tst = tree2.find(555);
    // // tst = tree2.finder(555);
    // original = origin.find(555);
    // std::cout << "   find  555 " << *tst << std::endl;
    // std::cout << "   find  original   " << *original << std::endl;
    // tst = tree2.find(550);
    // std::cout << "   find  550..." << *tst << std::endl;
    // AVLTree<int>::NewIdeaIterator win;
    // win = tree2.find(10);
    // std::cout << "   find  10..." << *win << std::endl;
    // original = origin.find(10);
    // std::cout << "   find  original   " << *original << std::endl;
    // original = origin.find(555);
    // win = tree2.finder(250);
    // std::cout << "   find  original   " << *original << std::endl;
    // tree2.dump4(tree2.root);

    // tree2.erase(5);
    // // std::cout << "   finder  " << *win << std::endl;
    // std::cout << tree2.size() << "    size    "  << std::endl;
    // std::cout << origin.size() << "   original size    "  << std::endl;

    // AVLTree<int> ypoc = tree2;
    // // ypoc.root = xerox(tree2.root);
    // // tree2.dump4(tree2.root);
    // AVLTree<int> vlt{tree2};
    // vlt.dump4(vlt.root);
    // pinus.dump4(pinus.root);
    // tree2.dump4(tree2.root);
    // BinTreeIterator oak;

    // std::cout << *tst << "  Now i can find smth " << std::endl;
    // std::cout << *original << "  Original can find smth " << std::endl;
    // origin.

    return 0;
}