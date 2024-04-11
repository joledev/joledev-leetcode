#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Función para crear un nuevo nodo de árbol binario
struct TreeNode* newNode(int val) {
    // Asignar memoria para un nuevo nodo
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    // Asignar valores al nuevo nodo
    node->val = val;
    node->left = NULL; // Inicializar el hijo izquierdo como nulo
    node->right = NULL; // Inicializar el hijo derecho como nulo
    return node; // Devolver el nodo creado
}

// Función auxiliar para obtener la secuencia de hojas de un árbol
void get_leaf_sequence(struct TreeNode* root, int* leaf_sequence, int* count) {
    // Caso base: si el nodo es nulo, regresar
    if (root == NULL) return;

    // Si el nodo actual es una hoja, agregar su valor a la secuencia de hojas
    if (root->left == NULL && root->right == NULL) {
        leaf_sequence[(*count)++] = root->val; // Agregar el valor de la hoja al arreglo y aumentar el contador
    }

    // Recursivamente llamar a la función para los hijos izquierdo y derecho del nodo actual
    get_leaf_sequence(root->left, leaf_sequence, count);
    get_leaf_sequence(root->right, leaf_sequence, count);
}

// Función para comparar dos secuencias de hojas
bool compare_leaf_sequences(int* seq1, int* seq2, int size) {
    // Iterar a través de ambas secuencias
    for (int i = 0; i < size; i++) {
        // Si los elementos en la misma posición son diferentes, las secuencias no son iguales
        if (seq1[i] != seq2[i]) return false;
    }
    
    // Si todas las hojas son iguales en ambas secuencias, devolver verdadero
    return true;
}

// Función principal para verificar si dos árboles son leaf-similar
bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    // Obtener secuencia de hojas para el primer árbol
    int leaf_sequence1[200]; // Arreglo para almacenar la secuencia de hojas
    int count1 = 0; // Contador para mantener el tamaño de la secuencia
    get_leaf_sequence(root1, leaf_sequence1, &count1); // Llenar el arreglo con la secuencia de hojas

    // Obtener secuencia de hojas para el segundo árbol
    int leaf_sequence2[200]; // Arreglo para almacenar la secuencia de hojas
    int count2 = 0; // Contador para mantener el tamaño de la secuencia
    get_leaf_sequence(root2, leaf_sequence2, &count2); // Llenar el arreglo con la secuencia de hojas
    
    // Comparar las secuencias de hojas
    if (count1 != count2) return false; // Si los tamaños de las secuencias son diferentes, los árboles no son similares en hojas
    return compare_leaf_sequences(leaf_sequence1, leaf_sequence2, count1); // Comparar las secuencias de hojas
}

int main() {
    // Definir los árboles de los casos de prueba
    struct TreeNode* root1_case1 = newNode(3); // Crear el primer nodo del primer árbol
    // Construir el árbol con nodos y valores dados
    root1_case1->left = newNode(5);
    root1_case1->right = newNode(1);
    root1_case1->left->left = newNode(6);
    root1_case1->left->right = newNode(2);
    root1_case1->right->left = newNode(9);
    root1_case1->right->right = newNode(8);
    root1_case1->left->right->left = newNode(7);
    root1_case1->left->right->right = newNode(4);

    // Similarmente, construir los otros árboles de prueba
    // Definir y construir el segundo árbol de prueba
    struct TreeNode* root2_case1 = newNode(3); // Crear el primer nodo del segundo árbol
    root2_case1->left = newNode(5);
    root2_case1->right = newNode(1);
    root2_case1->left->left = newNode(6);
    root2_case1->left->right = newNode(7);
    root2_case1->right->left = newNode(4);
    root2_case1->right->right = newNode(2);
    root2_case1->right->right->left = newNode(9);
    root2_case1->right->right->right = newNode(8);

    // Definir y construir otros árboles de prueba
    struct TreeNode* root1_case2 = newNode(1); // Crear el primer nodo del tercer árbol
    root1_case2->left = newNode(2);
    root1_case2->right = newNode(3);

    struct TreeNode* root2_case2 = newNode(1); // Crear el primer nodo del cuarto árbol
    root2_case2->left = newNode(3);
    root2_case2->right = newNode(2);

    // Probar la función con los casos de prueba
    bool output1 = leafSimilar(root1_case1, root2_case1);
    bool output2 = leafSimilar(root1_case2, root2_case2);

    // Imprimir los resultados
    printf("Output1: %s\n", output1 ? "true" : "false");
    printf("Output2: %s\n", output2 ? "true" : "false");

    // Liberar la memoria asignada a los árboles
    free(root1_case1);
    free(root2_case1);
    free(root1_case2);
    free(root2_case2);

    return 0;
}
