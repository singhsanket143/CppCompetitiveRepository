#include<iostream>
#define ll long long int
template<typename T>
struct Node {
    std::string key;
    T value;
    Node<T>* next;

    Node(std::string k, T v) {
        key = k;
        value = v;
        next = NULL;
    }
};

template<typename T>
struct HashMap {
    int cs;
    int ts;
    Node<T> **arr;
    HashMap(int total_size = 2) {
        ts = total_size;
        cs = 0;
        arr = new Node<T>*[ts];
        for(int i = 0; i < ts; i++) {
            arr[i] = NULL;
        }
    }

    void display() {
        for(int i = 0 ; i < ts; i++) {
            Node<T> *temp = arr[i];
            if(temp == NULL) {
                std::cout<<"empty\n";
                continue;
            } else {
                while(temp != NULL) {
                    std::cout<<"("<<temp->key<<","<<temp->value<<")->";
                    temp = temp->next;
                }
                std::cout<<"\n";
            }
        }
    }
    int hashFunc(std::string key) {
        ll sum = 0;
        ll factor = 1;
        for(int i = 0 ; i < key.size(); i++) {
            sum = ((sum%ts) + ((int)key[i]*factor)%ts)%ts;
            factor = (factor%ts * 37%ts)%ts;
        }
        return (int)sum;
    }

    void rehash() {
        int old_size = ts;
        ts *= 2;
        Node<T>** oldTable = arr;
        arr = new Node<T>*[ts];
        for(int i = 0; i < ts; i++) {
            arr[i] = NULL;
        }
        for(int i = 0; i < old_size; i++) {
            Node<T> *temp = oldTable[i];
            while(temp != NULL) {
                insert(temp->key, temp->value);
                temp = temp->next;
            }
        }
    }

    void insert(std::string key, T value) {
        int bi = hashFunc(key);
        Node<T> * new_node = new Node<T>(key, value);
        if(search(key) != NULL) {
            Node<T> *temp = arr[bi];
            while(temp != NULL) {
                if(temp->key == key) {
                    temp->value = value;
                    return;
                }
                temp = temp->next;
            }
        }
        
        if(arr[bi] == NULL) {
            arr[bi] = new_node;
        } else {
            new_node->next = arr[bi];
            arr[bi] = new_node;
        }
        cs++;
        double loadFactor = (double)(cs) / ts;
        if(loadFactor > 0.5) {
            rehash();
        }
    }

    T search(std::string key) {
        int bi = hashFunc(key);
        Node<T> *temp = arr[bi];
        while(temp != NULL) {
            if(temp->key == key) {
                return temp->value;
            }
            temp = temp->next;
        }
        return NULL;
    }

};

int main(int argc, char const *argv[])
{
    /* code */
    HashMap<int> hash;
    hash.insert("mango", 27);
    hash.insert("apple", 7);
    hash.insert("mango", 2);
    hash.insert("grapes", 217);
    hash.insert("mango", 127);
    hash.insert("grapes", 1127);
    hash.insert("apple", 207);
    hash.insert("applepie", 227);
    hash.insert("pie", 7);
    hash.insert("mango", 74);
    hash.display();
    std::cout<<hash.search("pie");
    return 0;   
}
