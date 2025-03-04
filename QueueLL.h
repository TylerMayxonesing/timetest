        #ifndef _QUEUELL_H
        #define _QUEUELL_H

          #include <iostream>  // for NULL


        // Queue class -- linked list implementation
        //

        //
        // ******************PUBLIC OPERATIONS*********************
        // void enqueue( x )      --> Insert x
        // void dequeue( )        --> Return and remove least recently inserted item
        // Object getFront( )     --> Return least recently inserted item
        // bool isEmpty( )        --> Return true if empty; else false
        // void makeEmpty( )      --> Remove all items
        // ******************ERRORS********************************
        // Overflow and Underflow thrown as needed

        template <class Object>
        class QueueLL;

        template <class Object>
        class ListNodes
        {
            ListNodes( const Object & theElement = Object( ), ListNodes * n = NULL )
              : element( theElement ), next( n ) { }

            Object   element;
            ListNodes *next;

            friend class QueueLL<Object>;
        };

        template <class Object>
        class QueueLL
        {
          public:
            explicit QueueLL();
            bool isEmpty( ) const;
            bool isFull( ) const;
            const Object & getFront( ) const;
            void makeEmpty( );
            Object dequeue( );
            void enqueue( const Object & x );

          private:
						ListNodes<Object> *head;
            ListNodes<Object> *back;
        };

        //#include "QueueLL.cpp"
        #endif
