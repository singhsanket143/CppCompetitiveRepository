#include <bits/stdc++.h>
using namespace std;


class Node {
public:
	int key;
	Node **forward;
	Node(int k, int level) {
		this->key = k;
		forward = new Node*[level+1];
		memset(forward, 0, sizeof(Node*)*(level+1));
	}
};

class SkipList {
public:
	int maxLvl;
	float p;
	int level;
	Node *header;
	SkipList(int lvl, float p) {
		this->maxLvl = lvl;
		this->p = p;
		this->level = 0;
		this->header = new Node(-1, maxLvl);
	}
	int randomLevel() {
		int lvl = 0;
		float r = (float)rand()/RAND_MAX;
		while(r < this->p and lvl < this->maxLvl) {
			lvl++;
			r = (float)rand()/RAND_MAX;
		}
		return lvl;
	}
	Node* createNode(int key, int level) {
		Node* n = new Node(key, level);
		return n;
	}
	void insert(int key) {
		Node* curr = this->header;
		Node *update[this->maxLvl+1];
		memset(update, 0, sizeof(Node*)*(this->maxLvl+1));
		for(int i = this->level; i >= 0; i--) {
			while(curr->forward[i] != NULL and curr->forward[i]->key < key) {
				curr = curr->forward[i];
			}
			update[i] = curr;
		}
		curr = curr->forward[0];
		if (curr == NULL || curr->key != key)
    	{
        int rlevel = randomLevel();
        if (rlevel > this->level)
        {
            for (int i=level+1;i<rlevel+1;i++)
                update[i] = this->header;
            level = rlevel;
        }
        Node* n = createNode(key, rlevel);
        for (int i=0;i<=rlevel;i++)
        {
            n->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = n;
        }
    }
	}
};

int main(int argc, char const *argv[])
{
	
	return 0;
}