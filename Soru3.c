#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Trie Düğüm Yapısı
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};

// Yeni bir Trie düğümü oluşturan fonksiyon
struct TrieNode *getNode(void) {
    struct TrieNode *pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    if (pNode) {
        pNode->isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }
    return pNode;
}

// Trie ağacına kelime ekleme algoritması
void insert(struct TrieNode *root, const char *key) {
    int level;
    int length = strlen(key);
    int index;
    struct TrieNode *pCrawl = root; // Kökten başla

    for (level = 0; level < length; level++) {
        index = key[level] - 'a'; // Karakterin alfabedeki sırası (sadece küçük harf varsayımı)
        
        // Eğer harf yoksa yeni düğüm oluştur
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
            
        pCrawl = pCrawl->children[index]; // Bir alt düğüme geç
    }
    // Kelimenin bittiğini işaretle
    pCrawl->isEndOfWord = true;
}

int main() {
    // Kök düğümü oluştur
    struct TrieNode *root = getNode();
    
    // Kelimeleri ağaca ekle
    insert(root, "vize");
    insert(root, "veri");
    insert(root, "yapi");
    
    printf("Trie agacina 'vize', 'veri' ve 'yapi' kelimeleri basariyla eklendi.\n");
    
    return 0;
}
