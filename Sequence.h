#pragma once

#ifndef SEQUENCE_H//���� ���������� �� ����������, �� cout � ����; ���� ����� ��������� �� ������ �� ���������.
#define SEQUENCE_H

template <class T>
class Sequence
{
public:
    virtual int getLength() const = 0;//virtual ����� ��� ������������ ������� (�.�. ��� �����������)
    virtual T getFirst() const = 0;//�������� ������ ������� � ������
    virtual T getLast() const = 0;
    virtual T get(const int i) const = 0;//�������� ������� �� �������


    virtual void append(T value) = 0;//��������� ������� � ������
    virtual void prepend(T value) = 0;//��������� ������� � �����
    virtual void insertAt(const int index, T value) = 0;//��������� ������� � �������� ������

};

#endif
