#include <iostream>

template <class T>
class Array
{
    //---------------//
    //    Private    //
    //---------------//
private:
    T* arr;
    int size;
    int grow;
    int count;

    //----------------//
    //     Public     //
    //----------------//
public:
    //----------------//
    //  Constructors  //
    //----------------//
    Array(T* arr, int size)
    {
        this->size = size;
        this->arr = new T[size];
        for (int i = 0; i < size; i++)
        {
            this->arr[i] = arr[i];
        }
        grow = size;
        count = size;
    }
    ~Array(){ delete[] arr; }

    //---------------//
    //    Methods    //
    //---------------//

        //--------//
        //  Size  //
        //--------//
    int getSize() const { return size; }
    void setSize(int size, int grow)
    {
        T* temp = new T[size];
        if (this->size < size)
        {
            for (int i = 0; i < this->size; i++)
                temp[i] = this->arr[i];
            for (int i = this->size; i < size; i++)
                temp[i] = T();
        }

        else if (this->size > size)
        {
            for (int i = 0; i < size; i++)
                temp[i] = arr[i];
        }
        delete[] arr;
        this->size = size;
        this->arr = temp;
        this->grow = grow;
    }
    void setSize(int size)
    {
        T* temp = new T[size];
        if (this->size < size)
        {
            for (int i = 0; i < this->size; i++)
                temp[i] = this->arr[i];
            for (int i = this->size; i < size; i++)
                temp[i] = T();
        }

        else if (this->size > size)
        {
            for (int i = 0; i < size; i++)
                temp[i] = arr[i];
        }
        delete[] arr;
        this->size = size;
        this->arr = temp;
    }
    void freeExtra()
    {
        T* temp = new T[count];
        if (count < size)
            for (int i = 0; i < count; i++)
                temp[i] = arr[i];
        else
        {
            for (int i = 0; i < size; i++)
                temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        size = count;
    }
    void removeAll()
    {
        delete[] arr;
        arr = nullptr;
        size = 0;
        count = 0;
        grow = 0;
    }
        //----------//
        //  Status  //
        //----------//
    T* getData() {return arr;}
    const T* getData() const {return arr;}
    int getUpperBound() const { return count; }
    bool isEmpty() const
    {
        if (count == 0)
            return true;
        return false;
    }
        //-----------//
        //  Element  //
        //-----------//
    T getAt(int index) const
    {
        if (index > size && index > 0)
        {
            return T();
        } else
        {
            return arr[index];
        }
    }
    void setAt(int index, T var)
    {
        if (index < size && index >= 0)
            arr[index] = var;
    }
    // NOT WORK \/ //
    void insertAt(int index, T var)
    {
        if (index < size && index >= 0)
        {
            T temp1[index - 1];
            T temp2[size - index];
            for (int i = 0; i < size; i++)
            {
                if (i < index)
                    temp1[i] = arr[i];
                else if (i > index)
                    temp2[i] = arr[i];
            }
            if (index == size - 1)
            {
                setSize(size + grow, grow);
            }
            for (int i = 0; i > size; i++)
            {
                if (i < index)  { arr[i] = temp1[i]; }
                else if (i > index)  { arr[i] = temp2[i]; }
                else  { arr[index] = var; }
            }
        }
    }
    // NOT WORK /\ //
    T operator[](int index) const
    {
        return getAt(index);
    }
    T& operator[](int index)
    {
        if (index < size && index >= 0)
            return arr[index];
        return arr[0];
    }
        //------------//
        //  Modifies  //
        //------------//
    void add(T var)
    {
        if (count == size)
        {
            setSize(size + grow);
        }
        arr[count] = var;
        count++;
    }
    void append(Array other)
    {
        int newCount = this->count + other.count;
        if (this->size < newCount)
        {
            setSize(newCount);
        }

        for (int j = 0; j < other.count; j++)
        {
            this->arr[this->count + j] = other.arr[j];
        }
        this->count = newCount;
    }
    void operator=(Array other)
    {
        delete[] arr;
        arr = new T[other.count];
        for (int i = 0; i < other.count; i++)
        {
            arr[i] = other.arr[i];
        }
        size = other.count;
        grow = other.grow;
        count = other.count;
    }

    void print() const
    {
        if (isEmpty() == 0)
        {
            for (int i = 0; i < size; i++)
                std::cout << arr[i] << " ";
            std::cout << std::endl;
        }
        else
        {
            std::cout << "Array is clear" << std::endl;
        }
    }
};

int main()
{
    int const SIZE = 3;
    int arr[SIZE] = {30, 10, 20};
    Array<int> myArr1(arr, SIZE);

    return 0;
}