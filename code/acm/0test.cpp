#include <iostream>
#include <exception>
using namespace std;
class Operation
{
public:
    Operation() = default;
    virtual ~Operation(){}
    Operation(double numA, double numB)
    {
        this->numA = numA;
        this->numB = numB;

    }
    virtual double getResult()   //虚函数
    {
        double result = 0;
        return result;
    }

protected:
    double numA = 0;
    double numB = 0;
};


class OperationAdd : public Operation
{
public:
    OperationAdd(double numA, double numB)
    {
        this->numA = numA;
        this->numB = numB;
    }
    double getResult() override
    {
        double result = 0;
        result = numA + numB;
        return result;

    }
};

class OperationSub : public Operation
{
public:
    OperationSub(double numA, double numB)
    {
        this->numA = numA;
        this->numB = numB;
    }
    double getResult() override
    {
        double result = 0;
        result = numA - numB;
        return result;
    }

};

class OperationMul : public Operation
{
public:
    OperationMul(double numA, double numB)
    {
        this->numA = numA;
        this->numB = numB;
    }
    double getResult() override
    {
        double result = 0;
        result = numA * numB;
        return result;
    }

};

class OperationDiv : public Operation
{
public:
    OperationDiv(double numA, double numB)
    {
        this->numA = numA;
        this->numB = numB;
    }
    double getResult() override
    {
        double result = 0;
        if (numB == 0)
            throw exception("分母不为零");
        result = numA /numB;
        return result;
    }

};


class OperationFactory
{
public:
    static Operation *createOperate(char operate, double numA, double numB)
    {
        Operation *oper = nullptr;
        switch (operate)
        {
        case '+':
            oper = new OperationAdd(numA,numB);
            break;
        case '-':
            oper = new OperationSub(numA,numB);
            break;
        case '*':
            oper = new OperationMul(numA,numB);
            break;
        case '/':
            oper = new OperationDiv(numA,numB);
            break;
        }
        return oper;
    }
};

int main()
{
    try{

        OperationFactory operFact;
        Operation *oper = nullptr;
        double numA, numB;
        cout << "请输入数字A：" << endl;
        cin >> numA;
        char sign;
        cout << "请选择运算符号（+、-、*、/）：" << endl;
        cin >> sign;
        cout << "请输入数字B: " << endl;
        cin >> numB;

        oper = operFact.createOperate(sign,numA,numB);
        double result = oper->getResult();
        cout << "结果是：" << result << endl;
        delete Oper;

    }
    catch (exception &e)
    {
        cout << "您的输入有误：" << e.what() << endl;

    }
    return 0;
}