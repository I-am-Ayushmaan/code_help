#include<bits/stdc++.h>
using namespace std;
  


#define fi first
#define se second
#define pb(x) push_back(x)
#define ll long long
#define f(i,n) for(int i=0; i<n; ++i)
#define show(a) for(auto &i : a) cout<<i<<" ";
#define vi vector<int>
#define vvi vector<vector<int>>
#define pop pop_back
#define deb(x) cout<<x<<"###\n";

 

#define int long long

#define setbits(n) __builtin_popcountll(n);
 
 
 
struct Node {
	Node* arr[26]; 
	bool flag = false; 
 
	bool contains(char c) {
	    int val = c - 'a';
        if (val < 0 )   return 0;
		
		return (arr[c - 'a'] != NULL); 
	}
 
	void put(char c, Node* newNode) {
		arr[c - 'a'] = newNode; 
	}
 
	Node* getNext(char ch) {
		return arr[ch - 'a']; 
	}
 
	void setFlag() {
		flag = true; 
	}
 
	bool isFlagSet() {
		return flag; 
	}
};
 

 class trie{
    private:
Node* root = new Node();  
 public:
 trie(){ };
void insert(string word) {
	Node* temp = root; 
	for(int i = 0; i < word.size(); i++) {
		if(!temp->contains(word[i])) {
			Node* newNode = new Node(); 
			temp->put(word[i], newNode); 
		}
		temp = temp->getNext(word[i]); 
	}
	temp->setFlag(); 
}
 
bool search(string word) {
	Node* temp = root; 
	for(int i = 0; i< word.size(); i++) {
		if(temp->contains(word[i])) {
			temp = temp->getNext(word[i]); 
		}
		else {
			return false; 
		}
	}
	return temp->isFlagSet(); 
}
 
bool startsWith(string word) {
	Node* temp = root; 
	for(int i = 0; i < word.size(); i++) {
		if(temp->contains(word[i])) {
			temp = temp->getNext(word[i]); 
		}
		else {
			return false; 
		}
	}
	return true; 
}

 };

 signed main(){
 trie* tt = new trie();
  tt->insert("ajeeb");
  tt->insert("band");
  cout<<tt->search("band");
  cout<<tt->startsWith("ba");

}








/* 
// TRIES-II 
struct Node {
	Node* arr[26]; 
	int cntWordsEnd = 0;
	int cntPrefixs = 0; 
 
	bool contains(char c) {
		return (arr[c - 'a'] != NULL); 
	}
 
	void put(char c, Node* newNode) {
		arr[c - 'a'] = newNode; 
	}
 
	Node* getNext(char ch) {
		return arr[ch - 'a']; 
	}
 
	void increaseWordsEndsWith() {
		cntWordsEnd++; 
	}
 
	void increaseCntPrefixs() {
		cntPrefixs++; 
	}
 
	void decreaseWordsEndsWith() {
		cntWordsEnd--; 
	}
 
	void decreaseCntPrefixs() {
		cntPrefixs--; 
	}
 
 
	int getCountWordsEnd() {
		return cntWordsEnd; 
	}
 
	int getCntPrefixs() {
		return cntPrefixs; 
	}
};
 
Node* root = new Node();  
 
void insert(string word) {
	Node* temp = root; 
	for(int i = 0; i < word.size(); i++) {
		// there might be a previous instance of s[i]
		// previously there was word, now i am inserting worse
		if(!temp->contains(temp, word[i])) {
			Node* newNode = new Node(); 
			temp->put(word[i], newNode); 
		}
		temp->increaseCntPrefixs(); 
		temp = temp->getNext(word[i]); 
	}
	temp->increaseWordsEndsWith(); 
}
 
int countWordsEqualTo(string word) {
	Node* temp = root; 
	for(int i = 0; i< word.size(); i++) {
		if(temp->contains(word[i])) {
			temp = temp->getNext(); 
		}
		else {
			return false; 
		}
	}
	return temp->getCountWordsEnd(); 
}
 
int startsWith(string word) {
	Node* temp = root; 
	for(int i = 0; i < word.size(); i++) {
		if(temp->contains(word[i])) {
			temp = temp->getNext(); 
		}
		else {
			return 0; 
		}
	}
	return temp->getCntPrefixs(); 
}
 
void erase(string word) {
	Node* temp = root; 
	// If does not exists, no need to erase anything 
	if(search(word) == 0) return; 
 
	for(int i = 0;i<word.size(); i++) {
		temp->decreaseCntPrefixs(); 
		temp->getNext(); 
	}
	temp->decreaseWordsEndsWith(); 
}
 */
