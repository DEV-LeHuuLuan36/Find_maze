//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//// Định nghĩa cấu trúc cho một hạng tử trong đa thức
//struct Term {
//    int coefficient; // Hệ số
//    int exponent; // Số mũ
//    struct Term* next; // Con trỏ đến hạng tử tiếp theo
//};
//
//// Định nghĩa cấu trúc cho đa thức (DSLK của các hạng tử)
//struct Polynomial {
//    struct Term* head; // Con trỏ đầu danh sách
//};
//
//// Hàm tạo một hạng tử mới
//struct Term* createTerm(int coefficient, int exponent) {
//    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
//    newTerm->coefficient = coefficient;
//    newTerm->exponent = exponent;
//    newTerm->next = NULL;
//    return newTerm;
//}
//
//// Hàm thêm một hạng tử vào đa thức
//void addTerm(struct Polynomial* poly, int coefficient, int exponent) {
//    struct Term* newTerm = createTerm(coefficient, exponent);
//    if (poly->head == NULL) {
//        poly->head = newTerm;
//    }
//    else {
//        struct Term* current = poly->head;
//        while (current->next != NULL) {
//            current = current->next;
//        }
//        current->next = newTerm;
//    }
//}
//
//// Hàm hiển thị đa thức
//void displayPolynomial(struct Polynomial* poly) {
//    struct Term* current = poly->head;
//    while (current != NULL) {
//        printf("%dx^%d ", current->coefficient, current->exponent);
//        if (current->next != NULL) {
//            printf("+ ");
//        }
//        current = current->next;
//    }
//    printf("\n");
//}
//
//// Hàm xóa hạng tử có số mũ cho trước
//void deleteTerm(struct Polynomial* poly, int exponent) {
//    struct Term* current = poly->head;
//    struct Term* prev = NULL;
//    while (current != NULL) {
//        if (current->exponent == exponent) {
//            if (prev == NULL) {
//                poly->head = current->next;
//            }
//            else {
//                prev->next = current->next;
//            }
//            free(current);
//            return;
//        }
//        prev = current;
//        current = current->next;
//    }
//}
//
//// Hàm tính giá trị của đa thức khi biết giá trị x
//int evaluatePolynomial(struct Polynomial* poly, int x) {
//    int result = 0;
//    struct Term* current = poly->head;
//    while (current != NULL) {
//        result += current->coefficient * pow(x, current->exponent);
//        current = current->next;
//    }
//    return result;
//}
//
//// Hàm tính tổng của hai đa thức P và Q
//struct Polynomial addPolynomials(struct Polynomial* polyP, struct Polynomial* polyQ) {
//    struct Polynomial result;
//    result.head = NULL;
//
//    struct Term* termP = polyP->head;
//    struct Term* termQ = polyQ->head;
//
//    while (termP != NULL || termQ != NULL) {
//        int coeffP = (termP != NULL) ? termP->coefficient : 0;
//        int expP = (termP != NULL) ? termP->exponent : 0;
//
//        int coeffQ = (termQ != NULL) ? termQ->coefficient : 0;
//        int expQ = (termQ != NULL) ? termQ->exponent : 0;
//
//        int sumCoeff = coeffP + coeffQ;
//        addTerm(&result, sumCoeff, expP);
//
//        if (termP != NULL) {
//            termP = termP->next;
//        }
//        if (termQ != NULL) {
//            termQ = termQ->next;
//        }
//    }
//
//    return result;
//}
//
//// Hàm tính hiệu của hai đa thức P và Q
//struct Polynomial subtractPolynomials(struct Polynomial* polyP, struct Polynomial* polyQ) {
//    struct Polynomial result;
//    result.head = NULL;
//
//    struct Term* termP = polyP->head;
//    struct Term* termQ = polyQ->head;
//
//    while (termP != NULL || termQ != NULL) {
//        int coeffP = (termP != NULL) ? termP->coefficient : 0;
//        int expP = (termP != NULL) ? termP->exponent : 0;
//
//        int coeffQ = (termQ != NULL) ? termQ->coefficient : 0;
//        int expQ = (termQ != NULL) ? termQ->exponent : 0;
//
//        int diffCoeff = coeffP - coeffQ;
//        addTerm(&result, diffCoeff, expP);
//
//        if (termP != NULL) {
//            termP = termP->next;
//        }
//        if (termQ != NULL) {
//            termQ = termQ->next;
//        }
//    }
//
//    return result;
//}
//
//// Hàm tính tích của hai đa thức P và Q
//struct Polynomial multiplyPolynomials(struct Polynomial* polyP, struct Polynomial* polyQ) {
//    struct Polynomial result;
//    result.head = NULL;
//
//    struct Term* termP = polyP->head;
//    while (termP != NULL) {
//        struct Term* termQ = polyQ->head;
//        while (termQ != NULL) {
//            int prodCoeff = termP->coefficient * termQ->coefficient;
//            int prodExp = termP->exponent + termQ->exponent;
//            addTerm(&result, prodCoeff, prodExp);
//            termQ = termQ->next;
//        }
//        termP = termP->next;
//    }
//
//    return result;
//}
//
//// Hàm sắp xếp đa thức theo số mũ (Insertion Sort)
//void sortPolynomial(struct Polynomial* poly) {
//    struct Term* current = poly->head;
//    while (current != NULL) {
//        struct Term* nextTerm = current->next;
//        while (nextTerm != NULL) {
//            if (current->exponent < nextTerm->exponent) {
//                // Swap coefficients and exponents
//                int tempCoeff = current->coefficient;
//                int tempExp = current->exponent;
//                current->coefficient = nextTerm->coefficient;
//                current->exponent = nextTerm->exponent;
//                nextTerm->coefficient = tempCoeff;
//                nextTerm->exponent = tempExp;
//            }
//            nextTerm = nextTerm->next;
//        }
//        current = current->next;
//    }
//}
//
//void menu(struct Polynomial* poly, struct Polynomial* polyQ) {
//    //system("cls");
//    printf("1.Them da thuc P\n");
//    printf("2.Xoa\n");
//    printf("3.Sap xep\n");
//    printf("4.Them van giu thu tu\n");
//    printf("5.Tinh gia tri khi cho bien x\n");
//    printf("6.Them da thuc Q\n");  
//    printf("7. P + Q \n"); 
//    printf("8. P - Q \n");
//    printf("9. P * Q \n");
//    displayPolynomial(poly);
//    displayPolynomial(polyQ);
//}
//int main() {
//    struct Polynomial poly;
//    struct Polynomial polyQ;
//    struct Polynomial sumPoly;
//    struct Polynomial differencePoly;
//    struct Polynomial productPoly;
//    poly.head = NULL;
//    polyQ.head = NULL;
//    while (1) {
//        int chon,x,y,mu;
//        menu(&poly,&polyQ);
//        printf("Chon so ban muon chuong truong trinh thuc hien : ");
//        scanf_s("%d", &chon);
//        switch (chon)
//        {
//        case 1: printf("Nhap he so va so mu : "); scanf_s("%d%d", &x, &y);  
//                addTerm(&poly, x, y); break;
//        case 2: printf("cho mu de xoa : ");
//                scanf_s("%d", &mu);
//                deleteTerm(&poly, mu); break;
//        case 3: sortPolynomial(&poly); break;
//        case 4: printf("Nhap he so va so mu : "); scanf_s("%d%d", &x, &y);   
//                addTerm(&poly, x, y);
//                sortPolynomial(&poly); break;
//        case 5: printf("Nhap he so x : "); scanf_s("%d", &x);
//                printf("ket qua = %d\n",evaluatePolynomial(&poly,x)); break;
//        case 6: printf("Nhap he so va so mu : "); scanf_s("%d%d", &x, &y);
//                addTerm(&polyQ, x, y); break;
//        case 7: sumPoly = addPolynomials(&poly, &polyQ); 
//                printf("P + Q ="); displayPolynomial(&sumPoly); break;
//        case 8: differencePoly = subtractPolynomials(&poly, &polyQ);
//                printf("P - Q ="); displayPolynomial(&differencePoly); break;
//        case 9: 
//                productPoly = multiplyPolynomials(&poly, &polyQ);
//                printf("P * Q ="); displayPolynomial(&productPoly); break;
//        default:printf("\nNhap lai\n");
//            break;
//        }
//    }
//    return 0;
//}
