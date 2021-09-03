#include <iostream>
#include "p0_starter.h"

using namespace scudb;

int main() {
    RowMatrix<int> matrix_1(4,2);
    std::vector<int> inputs1 = {1,2,3,4,5,6,7,8};
    matrix_1.FillFrom(inputs1);
    std::cout << "Matrix_1" << std::endl;
    for(int i=0; i<4; i++){
        for(int j=0; j<2; j++){
            std::cout << matrix_1.GetElement(i,j) << " ";
        }
        std::cout << std::endl;
    }

    RowMatrix<int> matrix_2(4,2);
    std::vector<int> inputs2 = {5,7,8,3,2,4,5,6};
    matrix_2.FillFrom(inputs2);
    std::cout << "Matrix_2" << std::endl;
    for(int i=0; i<4; i++){
        for(int j=0; j<2; j++){
            std::cout << matrix_2.GetElement(i,j) << " ";
        }
        std::cout << std::endl;
    }

    std::unique_ptr<RowMatrix<int>> matrix_res1 = RowMatrixOperations<int>::Add(&matrix_1,&matrix_2);
    std::cout << "Matrix_1 + Matrix_2 =" << std::endl;
    for(int i=0; i<matrix_res1->GetRowCount(); i++){
        for(int j=0; j<matrix_res1->GetColumnCount(); j++){
            std::cout << matrix_res1->GetElement(i,j) << " ";
        }
        std::cout << std::endl;
    }

    RowMatrix<int> matrix_3(2,4);
    std::vector<int> inputs3 = {0,2,7,3,4,5,1,6};
    matrix_3.FillFrom(inputs3);
    std::cout << "Matrix_3" << std::endl;
    for(int i=0; i<2; i++){
        for(int j=0; j<4; j++){
            std::cout << matrix_3.GetElement(i,j) << " ";
        }
        std::cout << std::endl;
    }

    std::unique_ptr<RowMatrix<int>> matrix_res2 = RowMatrixOperations<int>::Multiply(&matrix_1,&matrix_3);
    std::cout << "Matrix_1 * Matrix_3 =" << std::endl;
    for(int i=0; i<matrix_res2->GetRowCount(); i++){
        for(int j=0; j<matrix_res2->GetColumnCount(); j++){
            std::cout << matrix_res2->GetElement(i,j) << " ";
        }
        std::cout << std::endl;
    }

    RowMatrix<int> matrix_4(4,4);
    std::vector<int> inputs4 = {5,1,6,6,5,9,1,6,0,7,2,4,6,0,2,8};
    matrix_4.FillFrom(inputs4);
    std::cout << "Matrix_4" << std::endl;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            std::cout << matrix_4.GetElement(i,j) << " ";
        }
        std::cout << std::endl;
    }

    std::unique_ptr<RowMatrix<int>> matrix_res3 = RowMatrixOperations<int>::GEMM(&matrix_1,&matrix_3,&matrix_4);
    std::cout << "Matrix_1 * Matrix_3 + Matrix_4 =" << std::endl;
    for(int i=0; i<matrix_res3->GetRowCount(); i++){
        for(int j=0; j<matrix_res3->GetColumnCount(); j++){
            std::cout << matrix_res3->GetElement(i,j) << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
