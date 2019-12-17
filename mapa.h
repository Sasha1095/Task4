//
//  mapa.h
//  BIG_Prog4_alotfile
//
//  Created by sasha on 08/12/2019.
//  Copyright © 2019 sasha. All rights reserved.
//

#ifndef mapa_h
#define mapa_h
#include <iostream>
#include <string.h>
#include <utility>
#include <exception>

namespace prog4 {
    
    template<class INDEX, class INFO>
    class MapIt;
    
    
    template<class INDEX, class INFO>
    class Map {
        friend class MapIt<INDEX, INFO>;
    private:
        static const int QUOTA = 10; ///< Additional memory that allocates when the array is full
        int SIZE;///< How many items you can put now
        int n; ///< current amount of items
        std::pair<INDEX, INFO> *arr; ///< My array of information
        int getPosition(const INDEX&)const; //
    public:
        Map() :SIZE(QUOTA), n(0), arr(new std::pair<INDEX, INFO>[QUOTA]) {};
        ~Map() { delete[] arr; };
        Map(const Map<INDEX, INFO> &);
        Map(Map<INDEX, INFO>&&) ;
        Map<INDEX, INFO>& operator =(const Map<INDEX, INFO> &);
        Map<INDEX, INFO>& operator = (Map<INDEX, INFO>&&);
        int emplace( INDEX , INFO );//
        int erase(INDEX);//
        typedef MapIt<INDEX, INFO> Iterator;
        Iterator begin();
        Iterator end();
        Iterator find(const INDEX &) const;
        INFO at (const INDEX &) const;
    };
    
    template<class INDEX, class INFO>
    inline MapIt<INDEX, INFO> Map<INDEX, INFO>::end()
    {
        return MapIt<INDEX, INFO>(this->arr + n,*this);
    }

    template<class INDEX, class INFO>
    inline Map<INDEX, INFO>& Map<INDEX, INFO>::operator=(const Map<INDEX, INFO>& a)
    {
        if (this != &a) {
            delete[] arr;
            arr = new std::pair<INDEX, INFO>[a.SIZE];
            SIZE = a.SIZE;
            n = a.n;
            for (int i = 0; i < a.SIZE; ++i) {
                arr[i] = a.arr[i];
            }
        }
        return *this;
    }
    
    template<class INDEX, class INFO>
    inline Map<INDEX, INFO>::Map( Map<INDEX, INFO>&& a):SIZE(a.SIZE), n(a.n),arr(a.arr)
    {
       a.arr = nullptr ;
        
    }
    
    
    
    template<class INDEX, class INFO>
    inline Map<INDEX, INFO>& Map<INDEX, INFO>::operator = ( Map<INDEX, INFO>&& a)
    {
        if(this != &a){
        delete [] arr;
       SIZE = a.SIZE;
        n = a.n;
        arr = a.arr;
        a.arr = nullptr;
        }
        return *this;
    }
    
    template<class INDEX, class INFO>
    inline Map<INDEX, INFO>::Map(const Map<INDEX, INFO>& a):SIZE(a.SIZE), n(a.n), arr(new std::pair<INDEX,INFO> [a.SIZE])
    {
        for (int i = 0; i < a.SIZE; ++i) {
            arr[i] = a.arr[i];
        }
    }
    
    
    
    template<class INDEX, class INFO>
    class MapIt {
    private:
        std::pair <INDEX, INFO> *cur;
        const Map<INDEX, INFO>& map;
    public:
        MapIt() :cur(0) {};
        MapIt(std::pair <INDEX, INFO> *a, const Map<INDEX, INFO>& map) :cur(a), map(map) {  };
        int operator !=(const MapIt<INDEX, INFO> &) const;
        int operator ==(const MapIt<INDEX, INFO> &) const;
        std::pair <INDEX, INFO>& operator *();
        std::pair <INDEX, INFO> *operator ->();
        MapIt<INDEX, INFO> & operator ++();
        MapIt<INDEX, INFO> & operator ++(int);
        
    };
    
    template<class INDEX, class INFO>
    inline int Map<INDEX, INFO>::getPosition(const INDEX &s) const
    {
        if (n == 0)
            return -1;
        int flr = n-1;
        int fll = 0;
        
        while(fll<=flr)
        {
            int mid = (fll + flr);
            
            if (arr[mid].first == s)
            {
                //std::cout<< "Key found"<<std::endl;
                return mid;
            }
            if (s < arr[mid].first)
                flr = mid - 1;
            else
                fll = mid + 1;
        }
        
        return -1;
        
    }
    
    
    template <class INDEX, class INFO>
    inline int Map<INDEX,INFO> :: erase(INDEX index)
    {
        int t = getPosition(index);
        if (t == -1)
        {
            //std::cout << "Key doesn't exsist" << std::endl;
            return 0;
        }
        else
        {
            n -=1;
            for (;n > t;t++)
                arr[n] = arr[n+1];
            // std::cout << "Key was deleted" << std::endl;
            return 0;
        }
        return 0;
    }
    
    
    
    
    template<class INDEX, class INFO>
    inline int Map<INDEX, INFO>:: emplace(INDEX index,INFO info)
    {
        if (getPosition(index)!=-1)
        {
            //std::cout << "Key exsists" << std::endl;
            return 0;
            
        }
        else
        {
            if (n >= SIZE)
            {
                SIZE += QUOTA ;
                std::pair<INDEX,INFO> *old = arr;
                arr = new std::pair<INDEX,INFO>[SIZE];
                for (int i = 0; n > i ;i++)
                    arr[i].first = old[i].first;
                delete []old;
            }
            
            int i = n;
            if (i==0)
            {
                n=n +1;
                arr[i].first = index;
                arr[i].second = info;
                return 0;
            }
            for (;(i !=0) && (index < arr[i-1].first) ;i--)
                arr[i]=arr[i-1];
            arr[i].first=index;
            arr[i].second= info;
            // std::cout << "Key " <<k.numb<< "  was added" <<std::endl;
            n ++;
            return 0;
        }
    }
    
    
    
    
    
    
    template<class INDEX, class INFO>
    inline int MapIt<INDEX, INFO>::operator!=(const MapIt<INDEX, INFO>&it) const
    {
        return cur != it.cur;
    }
    
    template<class INDEX, class INFO>
    inline int MapIt<INDEX, INFO>::operator==(const MapIt<INDEX, INFO>&it) const
    {
        return cur == it.cur;
    }
    
    template<class INDEX, class INFO>
    inline std::pair<INDEX, INFO>& MapIt<INDEX, INFO>::operator*()
    {
        return *cur;
    }
    
    template<class INDEX, class INFO>
    inline std::pair<INDEX, INFO>* MapIt<INDEX, INFO>::operator->()
    {
        return cur;
    }
    
    template<class INDEX, class INFO>
    inline MapIt<INDEX, INFO>& MapIt<INDEX, INFO>::operator++()
    {
        ++cur;
        if ( cur < map.arr &&cur > (map.arr +map.n))
            throw std::runtime_error("Error");
        return *this;
    }
    
    template<class INDEX, class INFO>
    inline MapIt<INDEX, INFO>& MapIt<INDEX, INFO>::operator++(int)
    {
        MapIt<INDEX, INFO> res(*this);
       // int i = 0;
        ++cur;
       
        if ( cur < map.arr &&cur > (map.arr +map.n))
            throw std::runtime_error("Error");
        return res;
    }
    
    
    // for iterator
    template<class INDEX, class INFO>
    inline MapIt<INDEX,INFO> Map<INDEX, INFO>::begin()
    {
        return MapIt<INDEX, INFO>(this->arr,*this);
    }
    
    
    
    template<class INDEX, class INFO>
    inline MapIt<INDEX, INFO>  Map<INDEX, INFO>::find(const INDEX &s) const
    {
        int i = getPosition(s) ;
        if (i < 0)
            i = n;
        return MapIt<INDEX, INFO>(this->arr + i,*this);
    }
    
    template <class INDEX, class INFO>
    inline INFO Map<INDEX,INFO>::at(const INDEX &s) const
    {
        int l = getPosition(s);
        if (l < 0)
            l = n;
        return (this->arr + l)->second;
    }
}
#endif /* mapa_h */
