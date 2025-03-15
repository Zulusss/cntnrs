#ifndef insert_many_set_hpp
#define insert_many_set_hpp

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <memory>
#include <sstream>
#include <utility>
// #include <iterator>
// #include <cstddef>
// #include <cstdarg>
// #include <limits>
// #include <initializer_list>
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
// template<typename T, typename... Args>
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
        Node* next;
        Node* left;
        Node* right;
        Node* prev;        
        
        int height;

        Node(T value) : data(value), next(nullptr), left(nullptr), right(nullptr), prev(nullptr), height(1) {}
    };
       
    class My_Iterator {
        public:
        
        My_Iterator() : currentNode(nullptr) {}

        My_Iterator(Node* startNode) : currentNode(startNode), is_end(currentNode == nullptr) {

        }

        My_Iterator(int number) : currentNode(), is_end(true) {
            while(number--) currentNode = currentNode->next;
            //for erase
        }
        
        bool hasNext() {
            // return currentNode->next ? true : false;
            return !parentStack.empty();
        }

 
        T& operator*() const {
            if(!is_end)
            return currentNode->data;
            else return currentNode->right->data;
        }
        My_Iterator& operator--(int) {
            if(currentNode->prev) return *this = currentNode->prev;
            else return *this;
          }

          My_Iterator& operator--() {
            if(currentNode->prev)
            return *this = currentNode->prev;
            else return *this;
          }

        My_Iterator& operator++(int) {
            // if(is_end) return *this;
            // if(currentNode->next) return *this = currentNode->next;
            // else return *this;
            //if(is_end) currentNode = findmax(root)->right;
            //else //if (currentNode->next) 
            if (currentNode)  currentNode = currentNode->next;
            //else currentNode = findmax(root)->right;
        // std::cout << *this << *this== nullptr << std::endl;
        return *this;
          }

        My_Iterator& operator++() {
            
            if(is_end) return *this = is_end;
            // else if
            // (currentNode->next) 
            return *this = currentNode->next;
            // else return *this = currentNode->right;
            // else return *this;

            // do {
            
            //     if(is_down && currentNode->left){
            //         is_down = true;
            //         is_right = false;
            //         ret = currentNode;
            //         parentStack.push(currentNode);
            //         currentNode = currentNode->left;}

            //     else if(!is_down && currentNode->right){
            //         is_down = true;
            //         is_right = true;
            //         ret = currentNode;
            //         parentStack.push(currentNode);
            //         ret = currentNode = currentNode->right;}
            //     else {
            //         if (is_down) {
            //             is_down = false;
            //             // if(!is_right)                    
            //             ret = currentNode;
            //             std::cout << ret->data << " from first time ++ " << std::endl;
            //         }
            //         else {
            //             std::cout << currentNode->data << " ret" << std::endl;
            //             currentNode = parentStack.top();
            //             parentStack.pop();
            //         }
            //       }
            //       std::cout << currentNode->data << " Another after do" << std::endl;
                    
            // } while(is_down || is_right);
            // std::cout << ret->data << " before return from ++ " << std::endl;
            // this->currentNode = ret;
            
            // // return ret;
            // return *this;
        }

        bool operator==(const My_Iterator& other) const {
            // return currentNode != other.currentNode;
            return is_end ? other.is_end : currentNode == other.currentNode;
        }
        bool operator!=(const My_Iterator& other) const {
            return !(*this == other);
        }

    public:
        Node* currentNode = root;
        // Node* start = root;
        bool is_end;
        // Node* finish = nullptr;
        // Node* start = root.begin();
        std::stack<Node*> parentStack;
        bool is_down = true;
        bool is_right = false;
        // size_t position = 0;
    };

    // class HateCrewIterator{

    // };

    void linkNodes(Node* node) {
        static Node* lastVisited = nullptr;
        if (!node) {return;}
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
        Node* fin = findmax(root);
        fin->next = fin->right;
    }

    size_t how_much = 0;
    // bool contact{false};
    
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

    // class NewIdeaIterator {
    // // friend class AVLTree<T>;
    // public:
    // Node* current;
    // NewIdeaIterator() : current(nullptr) {}
    // NewIdeaIterator(Node* node) : current(node) {}
    

    // T& operator*() {
    //     return current->data;
    // }

    //     reference operator*() const {
    //         if(current) return current->data;
    //         throw std::runtime_error("Dereferencing a null iterator");

    //     }
    // };

    // class SetIterator {
    // public:
    //     SetIterator(Node* root) {
    //         pushLeft(root);
    //     }
    
    //     bool hasNext() {
    //         return !nodeStack.empty();
    //     }
    
    //     T next() {
    //         if (!hasNext()) {
    //             throw std::out_of_range("No more elements in the iterator");
    //         }
    
    //         Node* currentNode = nodeStack.top();
    //         nodeStack.pop();
    //         pushLeft(currentNode->right);
    //         return currentNode->data;
    //     }

    //     Node* stop_pushing(size_t stop){
    //         Node* result = nodeStack.top();
    //         while(stop--)
    //         nodeStack.pop();
    //         if(hasNext())
    //         result = nodeStack.top();
    //         return result;
    //     }

    //     SetIterator Iterator_pos(size_t cnt_inside=0){
    //         cnt = cnt_inside;
    //         pushLeft(root);
    //         Node* currentNode = nodeStack.top();
    //         while(cnt--){
    //             nodeStack.pop();
    //             currentNode = nodeStack.top();
    //         }
    //         return currentNode;
    //     }
    
    // private:
    //     std::stack<Node*> nodeStack;
    //     size_t cnt = 0;
    //     void pushLeft(Node* node) {
    //         while (node) {
    //             cnt++;
    //             nodeStack.push(node);
    //             node = node->left;
    //         }
    //     }
    // };

    My_Iterator begin(){
        linkin_park();
        Node* ret = findmin(root);
        return My_Iterator(ret);
    }

    My_Iterator end(){
        // return My_Iterator{findmax(root)->right};
        return My_Iterator{nullptr};
        // if(!root) return My_Iterator(nullptr);
        // else{
        // linkNodes(root);
        // linkNodes_backward(root);
        // Node* ret = findmax(root);
        // // Node* last{nullptr};
        // // ret->right = last;
        // return My_Iterator(ret);
        // }
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
            node = nullptr;
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
        if(num < 1 || num > (int)how_much) std::cout << "Incorrect num" << std::endl;
        Node* victim =  findKthNode(root,  num);
        std::cout << victim->data << " victim "  <<  std::endl;
        root = remove(root, victim->data);
     
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

    Node* Insert_Node(Node* node, Node* apx){
        if(!node) {how_much++; node = apx; node->left = node->right = node->next = node->prev = nullptr; node->height = 1; return node;}
        if (apx->data < node->data) {
            node->left = Insert_Node(node->left, apx);
        } else if (apx->data > node->data) {
            node->right = Insert_Node(node->right, apx);
        } else {
             return node; // Дубликаты не разрешены contact{true};
        }
        return Balance(node);
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
    // if(!node) return 0;
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

Node* remove_erase(Node* node){
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

Node* cut(Node* node, T data){
    if(!node) return 0;
    if(data < node->data)
        node->left = cut(node->left, data);
    else if(data > node->data)
        node->right = cut(node->right, data);
    else{
        how_much--;
        Node* left = node->left;
        Node* right = node->right;
        // delete node;
        if(!right) return left;
        Node* min = findmin(right);
        if(min)
        std::cout << "Min right (now min)  " << min->data << std::endl;
        else std::cout << "No min" << std::endl;
        min->right = RemoveMin(right);
        if(min->right)
        std::cout << "Min right after remove min    " << min->right->data << std::endl;
        else std::cout << "No min->right" << std::endl;
        min->left = left;
        if(min->left)
        std::cout << "Min left   " << min->left->data << std::endl;
        else std::cout << "No min->left" << std::endl;
        return Balance(min);
    }
    return Balance(node);   //maybe not needed
}

Node* append(Node* node, T value, Node* appendix, Node* second_root) {    //in-order л-п-к
    if (!node) {
        how_much++;
        second_root = cut(second_root, value);
        std::cout << "Second_root    " << second_root->data << std::endl;

        // appendix = Balance(appendix);
        // node = appendix.SuperFind(appendix.root, value);
        // appendix.root = cut(appendix.root, value);
        // node->left = node->right = nullptr;
        // appendix->left = appendix->right = nullptr;
        
        std::cout << "Working" << std::endl;
        std::cout << "App height " << appendix->height <<std::endl;
        appendix->height = 1;
        return Balance(appendix);
        // return Balance(node);
    }
    if(!appendix) {std::cout << "No app" << std::endl; return node;}

    if (value < node->data) {
        node->left = append(node->left, value, appendix, second_root);
    } else if (value > node->data) {
        node->right = append(node->right, value, appendix, second_root);
    } else {
        std::cout << "Дубликаты не разрешены" << std::endl;
         return node; // Дубликаты не разрешены contact{true};
    }

    // updateHeight(node);
    std::cout << "Happy end?    " << node->data << std::endl;
    return Balance(node);

    // int balance = balanceFactor(node);
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

void erase(My_Iterator pos) {
    std::cout << " This is it ... realy erase " << std::endl;
    // root = remove_erase(pos.currentNode);
    // root = remove(pos.currentNode, pos.currentNode->data);

    if (pos.currentNode == nullptr) {
        std::cout << "Iterator is null, cannot erase." << std::endl;
        return;
    }

    // Получаем данные узла, который нужно удалить
    T valueToRemove = pos.currentNode->data;

    // Удаляем узел из дерева
    root = remove(root, valueToRemove);
}


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

    void swap(AVLTree& other){
        // this* = std::swap(this, other);
        // if(this != other){
        //     AVLTree tmp;
        //     tmp = std::move(root);
        //     clear(root);
        //     *this = std::move(tmp);
        //     *this = tmp;
        // }
    }

    void m2(AVLTree& other) { 
        //this->linkin_park();
        //other.linkin_park();
        // int count = 0;
        // for(auto it_o: other)
        //     for(auto it: *this){
        // for(My_Iterator it_o = other.begin(); it_o.currentNode ; ++it_o)
        // int count = 0;
        for(My_Iterator it = this->begin(), it_o = other.begin(); (it != nullptr && it_o != nullptr) ;){
            // count++;
            if(it != nullptr &&  it_o != nullptr) {std::cout << "it " << *it << " it_o " << *it_o << std::endl;
                if(*it_o < *it) ++it_o;
                else if(*it_o > *it) ++it;
                else {++it; ++it_o;}
            }
            else if(it != nullptr) {
                std::cout << "it " << *it << " it_o == nullptr" << std::endl;
                ++it;
            }
            else {
                std::cout << "it_o " << *it_o << " it == nullptr" << std::endl;
                ++it_o;
            }
            //  if(*it_o < *it) {if(it_o != nullptr) {++it_o; std::cout << " iiiiinside " << *(it) << " " << *(it_o) << " " << std::endl;}
            //                 else { std::cout << " it_o == null " << *(it) << *(it_o) << std::endl;}
            //                 }
            //     else if(*it_o > *it) {if(it != nullptr) {++it; std::cout << " iiiiinside " << *(it) << " " << *it_o << " " << std::endl;}
            //                  else {std::cout << " it == null " << *(it) << *(it_o) << std::endl;}
            //                 }
            //  else {if(it != nullptr) ++it; if(it_o != nullptr) ++it_o; std::cout << " same " << *(it) << " " << *it_o << " " << std::endl;}
        }
    }
    void merge(AVLTree& other){
        this -> linkin_park();
        Node* start = this->findmin(root);
        other.linkin_park();
        Node* start_other = other.findmin(other.root);
        std::cout << "first  " << start->data << " second  " << start_other->data << std::endl;
        int how_much_nodes_will_be_merged =
        mergeLists(start, start_other);
        if(how_much_nodes_will_be_merged) {
            how_much_nodes_will_be_merged += how_much;
            std::cout << how_much_nodes_will_be_merged << " hmnwbm " << std::endl;
            root = listToBST(start, how_much_nodes_will_be_merged);
        }
    }
        // for(size_t i = 1; i > how_much; i++)
        // for(My_Iterator it = this->begin(); it != this->end(); ++it)
        // // Node* old_second = xerox(other.root);
        //     // AVLTree old_second = other;
        //     if(!this->contains(other.mindata())) {
        //         Insert_Node(root, SuperFind(other.root, other.mindata()));
        //     } else if(!this->contains(other.maxdata())) {
        //         std::cout << " Now insert   " <<  std::endl;
        //         Insert_Node(root, SuperFind(other.root, other.maxdata()));
        //     } else std::cout << " Not contains   " <<  std::endl;
        // }
        
        
            // for(int j = 1; j > other.how_much; j++){

            // for(My_Iterator it_other = old_second.begin(); it_other != old_second.end(); ++it_other ){
            //     if(!this->contains(*it_other)) 
            //     {
            //         std::cout << " append this ->  " << *it_other <<  std::endl;
            //         T value = *it_other; root = append(root, value, SuperFind(other.root, value), other.root );}

            //     if(*it > *it_other) it.currentNode->prev = it_other.currentNode;
            //     Node* tmp;
            //     if(start->data == start_other->data)
            //     if(*it == *it_other) continue;
            //     else{

            //     }
            // }
    // }
    // Функция для слияния двух списков
    int mergeLists(Node*& head1, Node* head2) {
        int count = 0;
        Node* current1 = head1;
        Node* current2 = head2;
        Node* prev1 = nullptr;
    
        while (current2) {
            while (current1 && current1->data < current2->data) {
                std::cout << current1->data   << " 1 " << current2->data << " 2" << std::endl;
                // std::cout << current1->data << " " <<current2->data << std::endl;
                prev1 = current1;
                current1 = current1->next;
            }
    
            if (!current1) {
                std::cout << "end of the line 1" << std::endl;
                // Если current1 достиг конца списка, добавляем оставшиеся элементы head2
                if (prev1) {
                    prev1->next = current2;
                    current2->prev = prev1;
                } else {
                    head1 = current2; // Если head1 был пуст, начинаем список с current2
                }
                while (current2) {
                    count++;
                    current2 = current2->next;
                    std::cout << current2->data << " c2 " << count << " count " << std::endl;
                }
                break;
            }
    
            if (current1 && current1->data == current2->data) {
                // Элемент уже существует, пропускаем
                std::cout  << current1->data << " c1 = c2 " << std::endl;
                current2 = current2->next;
                current1 = current1->next;
                count++;
                continue;
            }
    
            // Перемещаем current2 в список head1
            // Node* next2 = current2;
            Node* next2 = current2->next;
            // current2->prev = prev1;
            current2->prev = current1;
            current2->next = current1->next;
    
            if (prev1) {
                prev1->next = current1;
            } else {
                head1 = current2; // Обновляем голову списка, если вставка в начало
            }
    
            if (current1) {
                current1->prev = current1;
            }
    
            prev1 = current2; // Обновляем prev1 для следующей итерации
            current2 = next2; // Переходим к следующему узлу в head2
            std::cout << "how_many_times?" << std::endl;
            count++;
        }
        std::cout << count << " count " << std::endl;
        // count = 3;
        return count;
    }

// Функция для восстановления дерева из списка
Node* listToBST(Node*& head, int n) {
    if (head == nullptr || n <= 0) {
        std::cout << "head is nullptr or n <= 0" << std::endl;
        return nullptr;
    }
    std::cout << head->data << " head->data " << n << " n" << std::endl;
    Node* leftChild = listToBST(head, n / 2);
    Node* root = head;
    std::cout << root->data << " root->data " << std::endl;
    root->left = leftChild;
    // std::cout << leftChild->data << " rld " << std::endl;
    head = head->next;
    root->right = listToBST(head, n - n / 2 - 1);
    return root;
}
    template<typename... Args>
    std::vector<std::pair<My_Iterator, bool>> insert_many(Args&&... args);
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

    AVLTree<int> oak = {99, 33, 55, 44, 10, 3};
    // AVLTree<int> *oak = new AVLTree(  {99, 33, 55, 44} );
    //if (oak != NULL){};
    // delete oak;
    // oak.dump4(oak.root);
    // std::cout << "Lets try auto way " << std::endl;
    // for(auto i: oak) std::cout << i <<  " "  << std::endl;
    // std::cout << " This is it? " << std::endl;
    // auto it = oak.begin();
    // ++it;
    // std::cout << *it << std::endl;
    // ++it;
    // std::cout << *it << std::endl;
    // ++it;
    // std::cout << *it << std::endl;
    // ++it;
    // std::cout << *it << std::endl;
    // ++it;
    // std::cout << *it << std::endl;
    // ++it;
    // std::cout << *it << std::endl;
    // ++it;
    // std::cout << *it << std::endl;
    // oak.erase(2);
    // oak.print();

    AVLTree<int> pinus;
        for (size_t i = 1; i < 4; i++)
    {
        // /* code */tree2.insert(rand() % 1000);
        pinus.insert(i);
        // origin.insert(i);
        // origin.insert(rand() % 1000);
    }

    // auto Roman = oak.begin();
    
    // std::cout << *Roman << "   Roman   " <<std::endl;
    // ++Roman;
    // std::cout << *Roman << "   Roman   " <<std::endl;
    // ++Roman;
    // std::cout << *Roman << "   Roman   " <<std::endl;
    // ++Roman;
    // // std::cout << *Roman << "   Roman   " <<std::endl;
    // // --Roman;
    // // std::cout << *Roman << "   Roman   " <<std::endl;
    // // --Roman;
    // // std::cout << *Roman << "   Roman   " <<std::endl;
    // // --Roman;
    // // std::cout << *Roman << "   Roman   " <<std::endl;

    // // auto not_Roman = pinus.end();
    // // std::cout << *not_Roman << "     not_Roman" << std::endl;

    // // --not_Roman;
    // // std::cout << *not_Roman << "     not_Roman" << std::endl;
    // // // for(auto narcoMan = pinus.begin(); narcoMan != pinus.end(); narcoMan++)
    // // //     {std::cout << *narcoMan << std::endl;}
    
    // // // for(auto narcoMan2 = pinus.end(); narcoMan2 != pinus.begin(); narcoMan2--)
    // // //     {std::cout << *narcoMan2 << std::endl;}
    
    // // std::cout<< std::endl;
    
    // // AVLTree<int>::My_Iterator fck;
    // // fck = pinus.findmin(pinus.root);
    // // std::cout << *fck << "  min  " << std::endl;
    // // fck = pinus.findmax(pinus.root);
    // // std::cout << *fck << "  max  " << std::endl;

    // // std::cout << pinus.size() << "  size    " << std::endl;

    // // fck = pinus.find(0);
    // // std::cout << *fck << "  find 0  " << std::endl;
    // // fck = pinus.find(500);
    // // std::cout << *fck << "  find 500  " << std::endl;
    // // ++fck;
    // // std::cout << *fck << "  ++  " << std::endl;
    // // bool res = pinus.contains(555);
    // // std::cout  << res << "     contains  555" << std::endl;
    // // res = pinus.contains(5);
    // // std::cout  << res << "     contains  5" << std::endl;
    
    // // pinus.dump4(pinus.root);
    // // std::cout  << pinus.root->height << "     pin roo hei  " << std::endl;
    // // pinus.Balance(pinus.root);
    // // pinus.dump4(pinus.root);
    // // std::cout  << oak.root->height << "     oak roo hei " << std::endl;
    // pinus.erase(5);
    // // pinus.print();
    // // pinus.erase(32);
    // pinus.dump4(pinus.root);
    // pinus.merge(oak);
    // pinus.remove(pinus.root, 63);
    // pinus.cut(pinus.root, 63);
    // pinus.dump4(pinus.root);
    // pinus.merge(oak);
    pinus.m2(oak);
    // pinus.dump4(pinus.root);
    //pinus.print();
    // oak.erase(3);
    // oak.dump4(oak.root);
    // oak.cut(oak.root, 55);
    // oak.dump4(oak.root);
    // oak.cut(oak.root, 44);
    // oak.dump4(oak.root);
    // oak.cut(oak.root, 33);
    // oak.dump4(oak.root);
    // oak.cut(oak.root, 99);
    // oak.dump4(oak.root);
    //     oak.cut(oak.root, 55);
    // oak.dump4(oak.root);
    for(auto i: pinus) std::cout << i <<  " "  << std::endl;
    // pinus.insert_many(100, 500, 900);

    return 0;
}

#endif