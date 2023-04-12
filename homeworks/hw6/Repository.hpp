#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
class Repository {
    template <typename U>
    friend ostream &operator<<(ostream &, const Repository<U> &);

    private:
        vector<T> repo;
    public:
    // Constructor:
    Repository(vector<T> repo);

    void add_item(T item);
    void add_items(vector<T> items);
    int get_pos(T item);
    void remove_item(T item);
    void remove_items(vector<T> items); 
    int count_items();

};


template <typename T>
Repository<T>::Repository(vector<T> repo) {
    this->repo = repo;
};

template <typename T>
void Repository<T>::add_item(T item) {
    this->repo.push_back(item);

};

template <typename T>
void Repository<T>::add_items(vector<T> items) {
    for (auto& i : items) {
        this->repo.push_back(i);
    }
};

template <typename T>
int Repository<T>::get_pos(T item) {
    vector<T> repo = this->repo;
    auto it = find(repo.begin(), repo.end(), item);
  
    if (it != repo.end()) {
        int pos = it - repo.begin();
        return pos;
    }
    else {
        return -1;
    }
};

template <typename T>
void Repository<T>::remove_item(T item) {
    vector<T> rm_repo = this->repo;
    int pos  = this->get_pos(item);
    rm_repo.erase(rm_repo.begin() + pos);
    this->repo = rm_repo;
};

template <typename T>
void Repository<T>::remove_items(vector<T> items) {
    vector<T> rm_repo = this->repo; 
    for (auto& i : items) {
        int pos  = this->get_pos(i);
        rm_repo.erase(rm_repo.begin() + pos);
    }
    this->repo = rm_repo;
};

template <typename T>
int Repository<T>::count_items() {
    this->repo.size();
}

template <typename T>
ostream &operator<<(ostream &out, const Repository<T> &repository) {
    out << "Repository items: ";
    for(auto i : repository.repo) {

        out << i;

        if (i != (repository.repo).back()) {
            out << ", ";
        }
    }
    return out;
};
