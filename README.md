# Sparse Containers

[![Language: C++](https://img.shields.io/badge/language-C%2B%2B-blue.svg?style=flat&logo=c%2B%2B)](https://isocpp.org/)


### Linked-List Sparse Vector & Sparse Matrix in C++
- A sparse array (or sparse vector) is a data structure where most elements are zero, so instead of storing all positions, we only store the non-zero entries. This saves memory and makes operations faster when the data is extremely sparse.
<img src="https://github.com/user-attachments/assets/d46e3589-8e14-4077-85d6-3ae6398db926" alt="ArrayLinkedList illustration">



- A sparse matrix extends the same idea to 2D grids. Instead of keeping an entire R × C table full of zeros, each row stores only its non-zero column entries. This makes it efficient for scientific computing, graphs, and machine-learning workloads where matrices are huge but mostly empty.
<img src="https://github.com/user-attachments/assets/3bb97acf-98ba-4014-a617-629bad965d5d" alt="SparseMatrix example">

----

### Importance of Sparse Arrays and Sparse Matrices

1- Sparse arrays and sparse matrices play a crucial role in modern computing when dealing with large datasets containing predominantly zero values. Their key advantages include:

2- Memory Efficiency: Only non-zero elements are stored, significantly reducing memory requirements compared to dense structures.

3- Computational Performance: Algorithms operate exclusively on meaningful data, avoiding unnecessary computations on zeros.

4- Scalability: Enable handling of extremely large vectors and matrices that would be infeasible to store in dense format.

5- Efficient Mathematical Operations: Support fast addition, dot products, and matrix–vector multiplication, particularly in sorted or structured representations.

6- Applicability in Advanced Domains: Essential in scientific computing, optimization problems, graph algorithms, and machine-learning workloads where sparse data is common.

----

## Time Complexity & Memory
### SparseVector (n = vector size, k = non-zeros)

| Operation            | Sorted List (default) | Unsorted List (fast insert) |
|---------------------|----------------------|-----------------------------|
| `get(index)`         | O(k)                 | O(k)                        |
| `set(index, value)`  | O(k)                 | O(1)                        |
| `erase(index)`       | O(k)                 | O(k)                        |
| `iterate all nnz`    | Θ(k)                 | Θ(k)                        |
| `add(other)`         | Θ(k1 + k2)           | O(k1 * k2)                  |
| `dot(other)`         | Θ(k1 + k2)           | O(k1 * k2)                  |
| **Memory**           | O(k) nodes + overhead| O(k) nodes + overhead       |

### SparseMatrix (R = rows, C = cols, k_row = non-zeros per row, nnz = total non-zeros)

| Operation                 | Complexity (default sorted rows) |
|----------------------------|---------------------------------|
| `get(r,c)`                 | O(k_row)                        |
| `set(r,c)`                 | O(k_row)                        |
| `erase(r,c)`               | O(k_row)                        |
| `iterate all entries`      | Θ(nnz)                          |
| `matrix × vector (y = Ax)` | Θ(nnz)                          |
| `add(A,B)`                 | Θ(nnz_A + nnz_B)                |
| `transpose`                | Θ(nnz)                          |
| **Memory**                 | O(nnz) nodes + per-row heads    |


----

## Getting Started
Clone the repository to your local machine using Git:

```bash
git clone https://github.com/OMar-Adelll/SparseNet.git
cd SparseNet
```


----


## Contact
- **Author:** Omar Adel Youssef  
- **Repo:** [SparseNet](https://github.com/OMar-Adelll/SparseNet)



