# Sparse Containers — Linked‑List Sparse Vector & Sparse Matrix

[![Language: C++](https://img.shields.io/badge/language-C%2B%2B-lightgrey.svg)]()

A tiny, well-documented C++ library for sparse 1D arrays (SparseVector) and sparse matrices (SparseMatrix) using per-row linked lists. Designed for clarity, teaching, and memory‑constrained prototypes.

One-line pitch
- Minimal linked‑list based sparse containers providing deterministic iteration, merge-friendly arithmetic, and clear tradeoffs for upgrades to hash or CSR/CSC formats.

Why this project
- Purpose: efficiently represent very sparse data (most entries are zero) with minimal overhead.
- Audience: students, educators, and prototype authors who prioritize readability, determinism, and small memory footprint.
- Approach: one linked list per vector (or per matrix row) storing only non-zero entries. Default lists are sorted by index to enable linear-time merge operations.

Highlights
- SparseVector: set / get / erase / iterate / add / dot
- SparseMatrix: per-row lists with set / get / erase / iterate / add / multiply / transpose
- Default sorted lists for predictable merges; optional unsorted insertion mode for faster writes
- Small, auditable C++ headers and a strong, CI-ready test plan


Time & complexity (Big-O)

Notation
- n: dense length of a vector
- k: non-zeros in a vector
- R, C: rows and columns of a matrix
- k_row: non-zeros in a particular row
- nnz: total non-zeros in a matrix

SparseVector complexity summary

| Operation            | Sorted lists (default)        | Unsorted lists (fast writes)            |
|---------------------:|:------------------------------|:----------------------------------------|
| get(index)           | O(k) (scan)                   | O(k)                                    |
| set(index, value)    | O(k) (insert/replace at sorted position) | O(1) (head insert) + O(1) amortized for small ops |
| erase(index)         | O(k)                          | O(k) (scan to remove)                   |
| iterate (all nnz)    | Θ(k)                          | Θ(k)                                    |
| add(other)           | Θ(k1 + k2) (merge)            | O(k1 * k2) worst (need hashing or sorts)|
| dot(other)           | Θ(k1 + k2) (two‑pointer merge) | O(k1 * k2) worst                        |
| memory                | O(k) nodes + small overhead   | O(k) nodes + small overhead             |

SparseMatrix complexity summary

| Operation                 | Complexity (default sorted rows)          |
|--------------------------:|:------------------------------------------|
| get(r,c)                  | O(k_row)                                  |
| set(r,c)                  | O(k_row)                                  |
| erase(r,c)                | O(k_row)                                  |
| iterate all entries       | Θ(nnz)                                    |
| matrix × vector (y = A x) | Θ(nnz)                                    |
| add(A, B)                 | Θ(nnz_A + nnz_B) (row-wise merge)         |
| transpose                 | Θ(nnz) (rebuild rows from columns)        |
| matrix × matrix (naive)   | O(R * (cost per row) ), typically costly; convert to CSR/CSC for heavy compute |
| memory                    | O(nnz) nodes + per-row heads              |



Testing & validation strategy
- Unit tests:
  - set/get/erase correctness and edge cases
  - zero-removal (setting to zero removes nodes)
  - length / bounds checks
- Conversion tests:
  - dense ↔ sparse roundtrip (vectors and matrices)
- Arithmetic tests:
  - add, dot, matrix×vector compared with dense baseline
  - merge edge cases (overlapping, disjoint, identical indices)
- Stress tests:
  - Randomized insert/delete with deterministic seeds validated against dense impl
- Memory & correctness in CI:
  - AddressSanitizer / Valgrind runs
  - Deterministic test seeds
- Suggested frameworks:
  - GoogleTest or Catch2



Roadmap (prioritized)
1. v0.1 — Minimal, tested API: SparseVector and SparseMatrix (sorted lists), basic arithmetic, unit tests, CI.
2. v0.2 — Serialization (JSON row lists), to_dense/from_dense helpers, expanded tests.
3. v0.3 — Conversion utilities to/from CSR/CSC, per-row hash option, hybrid row strategy.
4. v1.0 — Performance tuning, optional Python bindings, documentation site.




Contact
- Author: Omar Adel Youssef 
- Repo: (https://github.com/OMar-Adelll/SparseNet.git)

