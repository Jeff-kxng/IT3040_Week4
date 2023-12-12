/*Bài tập 10: Search Engine */
#include <bits/stdc++.h>
using namespace std;
// Sok Sokong 20211005
int n, q;
vector<vector<string>> vector_train;
vector<vector<string>> vector_test;
vector<int> f_max; // Maximum word frequency in each document

// Function to split string by spaces or commas
vector<string> split_string(string str){
    vector<string> vt;
    stringstream ss(str);
    string token;
    while (getline(ss, token, ' ')) {
        if (token.find(",") != string::npos) {
            stringstream comma(token);
            string subtoken;
            while (getline(comma, subtoken, ',')) {
                vt.push_back(subtoken);
            }
        } else {
            vt.push_back(token);
        }
    }
    return vt;
}

// Input function
void input(){
    vector<string> document_train;
    vector<string> document_test;

    cin >> n;
    cin.ignore(); // Clear newline character from buffer
    for(int i = 0; i < n; i++){
        string str_tmp;
        getline(cin, str_tmp);
        document_train.push_back(str_tmp);
    }

    cin >> q;
    cin.ignore(); // Clear newline character from buffer
    for(int i = 0; i < q; i++){
        string str_tmp;
        getline(cin, str_tmp);
        document_test.push_back(str_tmp);
    }

    for(string v : document_train){
        vector<string> element = split_string(v);
        vector_train.push_back(element);
    }

    for(string v : document_test){
        vector<string> element = split_string(v);
        vector_test.push_back(element);
    }
}

// Preprocessing
void pre_processing(){
    for(vector<string> str_tmp : vector_train){
        map<string, int> m;
        int max_f = 0;
        for(string word_tmp : str_tmp){
            map<string, int>::iterator ite = m.find(word_tmp);
            if(ite == m.end()){
                m.insert({word_tmp, 1});
            } else {
                ite->second += 1;
            }
            max_f = max(m[word_tmp], max_f);
        }
        f_max.push_back(max_f);
    }
}

// Term frequency of a word in a document
double tf(int ftd, int maxfd) {
    return 0.5 + 0.5 * ((double) ftd / maxfd);
}

// Inverse document frequency of a word in the document collection
double idf(int dft, int n) {
    return log2((double) n / dft);
}

// Predicting the document label
int search_engine(vector<string> list_word){
    double score_max = -1000;
    int predict_label = -1;
    for(int i = 0; i < n; i++){
        vector<string> list_word_train_doc = vector_train[i];
        double score = 0;
        for(string word : list_word){
            if(find(list_word_train_doc.begin(), list_word_train_doc.end(), word) == list_word_train_doc.end()){
                continue;
            } else {
                int ftd = count(list_word_train_doc.begin(), list_word_train_doc.end(), word);
                int dft = 0;
                for(vector<string> str_tmp : vector_train){
                    if(find(str_tmp.begin(), str_tmp.end(), word) != str_tmp.end()){
                        dft++;
                    }
                }
                int maxfd = f_max[i];

                double tf_word = tf(ftd, maxfd);
                double idf_word = idf(dft, n);

                score += tf_word * idf_word;
            }
        }

        if(score > score_max) {
            predict_label = i;
            score_max = score;
        }
    }

    return predict_label + 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    pre_processing();

    for(int i = 0; i < q; i++)
        cout << search_engine(vector_test[i]) << endl;

    return 0;
}
