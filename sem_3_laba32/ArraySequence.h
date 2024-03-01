#include "Sequence.h"
#pragma once
#include "LinkedList.h"

template<typename T>
class ArraySequence : public Sequence<T>
{
private:
    DynamicArray<T>* dynamic_array;

public:

    ArraySequence() {
        this->dynamic_array = new DynamicArray<T>();
    };
    ArraySequence(int size) {
        this->dynamic_array = new DynamicArray<T>(size);
    };
    ArraySequence(DynamicArray<T>* arr) {
        this->dynamic_array =arr;
    };
    ArraySequence(const ArraySequence<T> & array) {
        this->dynamic_array = new DynamicArray<T>(*array.dynamic_array);
    };
    ArraySequence(T* data, int size)  {
        this->dynamic_array =new DynamicArray<T>(data, size);
    };


    T GetFirst() const override  {
        if (this->GetSize()==0) {
            throw out_of_range(INDEX_OUT_OF_RANGE);
        }
        return dynamic_array->Get(0);
    };

    T GetLast() const override{
        if (this->GetSize()==0) {
            throw out_of_range(INDEX_OUT_OF_RANGE);
        }
        return dynamic_array->Get(dynamic_array->GetSize()-1);
    };


    T Get(int index) const override  {
        if (index<0 || index>=this->GetSize()) {
            throw out_of_range(INDEX_OUT_OF_RANGE);
        }
        return dynamic_array->Get(index);
    };
    ArraySequence<T>* GetSubSequence(int start, int end) override{
        if (start<0 || start>=this->GetSize() || end<0 || end >=this->GetSize() || end<start) {
            throw out_of_range(INDEX_OUT_OF_RANGE);
        }
        ArraySequence<T>* newArray = new ArraySequence<T>();
        for (int i=start; i<=end; i++) {
            newArray->Append(this->Get(i));
        }
        return newArray;
    }

    int GetSize() const override {
        return dynamic_array->GetSize();
    };



    void Set(int index, T item) override {
        if (index<0 || index >=this->dynamic_array->GetSize()) {
            throw out_of_range(INDEX_OUT_OF_RANGE);
        }
        return this->dynamic_array->Set(index, item);
    };

    void Append(T item) override {
        DynamicArray<T>* newarr = new DynamicArray<T>(this->GetSize()+1);
        newarr->Set(this->GetSize(), item);
        for (int i=0; i<this->GetSize(); i++) {
            newarr->Set(i, this->Get(i));
        }
        this->dynamic_array=newarr;
    };

    void Prepend(T item) override  {
        DynamicArray<T>* newdynarr = new DynamicArray<T>(this->GetSize()+1);
        newdynarr->Set(0, item);
        for (int i=0; i<this->GetSize(); i++) {
            newdynarr->Set(i+1, this->Get(i));
        }
        this->dynamic_array=newdynarr;
    };

    void InsertAt(T item, int index) override {
        if (index<0 || index >=this->GetSize()) {
            throw out_of_range(INDEX_OUT_OF_RANGE);
        }
        int newSize = this->GetSize()+1;
        DynamicArray<T>* newdynarr = new DynamicArray<T>(newSize);
        int j=0;
        for (int i = 0; i<newSize; ++i) {
            if (i == index) {
                newdynarr->Set(i, item);
                continue;
            }
            newdynarr->Set(i, this->Get(j));
            j++;
        }
        dynamic_array = newdynarr;

    };

    void RemoveAt(int index) override {
        if (this->GetSize() < 1) {
            throw length_error(NEGATIVE_SIZE);
        }

        for (int i = index; i < this->GetSize() - 1; ++i) {
            this->dynamic_array->Set(i, this->dynamic_array->Get(i+1) );
        }

        this->dynamic_array->Resize(this->GetSize() - 1);
    }

    void Swap(int index1, int index2) override {
        T temp;
        temp = this->Get(index1);
        this->Set(index1, this->Get(index2));
        this->Set(index2, temp);
    }

    ArraySequence<T>* Concat(Sequence<T> *arr) override {
        ArraySequence<T>* newSequence=new ArraySequence<T>;
        for (int i = 0; i<this->GetSize(); i++) {
            newSequence->Append(this->Get(i));}
        for (int i=0;i<arr->GetSize();i++){
            newSequence->Append(arr->Get(i));
        }
        return newSequence;
    };

    Sequence<T>* Clone() override {
        Sequence<T>* seq = (Sequence<T>*) new ArraySequence<T>(*this);
        return seq;
    }

    virtual T operator[](const int index) override {
        return dynamic_array->Get(index);
    }

    ~ArraySequence() = default;

};