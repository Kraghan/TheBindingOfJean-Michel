//
// Created by Kraghan on 15/12/2016.
//

#ifndef BINDINGOFJEANMICHEL_SINGLETON_HPP
#define BINDINGOFJEANMICHEL_SINGLETON_HPP


template <typename T>
class Singleton
{
protected:
    static T * m_instance;
    Singleton() {};

public:

    static T * Instance()
    {
        if(m_instance == nullptr)
            m_instance = new T();

        return m_instance;
    }
};

template <typename T> T * Singleton<T>::m_instance = nullptr;


#endif //BINDINGOFJEANMICHEL_SINGLETON_HPP
