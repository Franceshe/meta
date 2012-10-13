/**
 * @file document.h
 */

#ifndef _DOCUMENT_H_
#define _DOCUMENT_H_

#include <memory>
#include <unordered_map>
#include <string>
#include "structs.h"

/**
 * Represents an indexed document.
 */
class Document
{
    public:

        /**
         * Constructor.
         * @param path - the path to the document
         */
        Document(const std::string & path);

        /**
         * Increment the count of the specified transition.
         * @param termID - the token count to increment
         * @param amount - the amount to increment by
         */
        void increment(TermID termID, unsigned int amount);

        /**
         * Increment the count of the specified transition.
         * @param termID - the token count to increment
         * @param amount - the amount to increment by
         * @param docFreq - used for IDF
         */
        void increment(TermID termID, unsigned int amount,
                std::shared_ptr<std::unordered_map<TermID, unsigned int>> docFreq);

        /**
         * @return the path to this document (the argument to the constructor)
         */
        std::string getPath() const;

        /**
         * @return the classification category this document is in
         */
        std::string getCategory() const;

        /**
         * @return the containing directory of a file given its full path
         */
        static std::string getCategory(const std::string & path);

        /**
         * @return the name of this document
         */
        std::string getName() const;

        /**
         * @return the total of transitions recorded for this Document.
         * This is not the number of unique transitions.
         */
        size_t getLength() const;

        /**
         * Get the number of occurrences for a particular transition.
         * @param termID - the termID of the term to look up
         */
        size_t getFrequency(TermID termID) const;

        /**
         * @return the map of frequencies for this document.
         */
        const std::unordered_map<TermID, unsigned int> & getFrequencies() const;
 
        /**
         * Prints tokenizer output in liblinear input format.
         */
        void printLiblinearData() const;

    private:

        /** where this document is on disk */
        std::string _path;

        /** which category this document would be classified into */
        std::string _category;

        /** the short name for this document (not the full path) */
        std::string _name;

        /** the number of (non-unique) tokens in this document */
        size_t _length;

        /** counts of how many times each token appears */
        std::unordered_map<TermID, unsigned int> _frequencies;

        /**
         * @return the name of a document given its full path
         */
        static std::string getName(const std::string & path);
};

#endif
