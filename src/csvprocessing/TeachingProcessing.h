/*
 * Child to CSVProcessing. Contains query methods for publications.
 *
 * Author(s): Kevin Stubbs
 */
#ifndef TEACHINGPROCESSING_H
#define TEACHINGPROCESSING_H
#include "../mainwindow.h"

#include "CSVProcessing.h"

using namespace std;

class TeachingProcessing : public CSVProcessing {

public:
/*
     * "data" columns
     */
    static const int COLUMN_PROGRAM = 2;
    static const int COLUMN_HOURS = 3;
    static const int COLUMN_NUMBER_STUDENTS = 4;

    /**
     * Constructor.
     *
     * @brief TeachingProcessing
     * @param filename
     */
    TeachingProcessing(string filename, int csvtype);

    /**
     * Getter/Refiner for status (e.g., Postgraduate Medical Education). Considers all indecies.
     *
     * @brief getIndicesStatus
     * @param status
     * @return
     */
    vector<int> getIndicesProgram(string program);

    /**
     * Getter/Refiner for status (e.g., Postgraduate Medical Education). Considers specified indecies.
     *
     * @brief getIndicesStatus
     * @param status
     * @param indToConsider
     * @return
     */
    vector<int> getIndicesProgram(string program, vector<int> indToConsider);

    /**
     * Getter/Refiner for number of hours. Considers all indecies.
     *
     * @brief getIndicesHours
     * @param minHours
     * @param maxHours
     * @return
     */
    vector<int> getIndicesHours(int minHours, int maxHours);

    /**
     * Getter/Refiner for number of hours. Considers specified indecies.
     *
     * @brief getIndicesHours
     * @param minHours
     * @param maxHours
     * @param indToConsider
     * @return
     */
    vector<int> getIndicesHours(int minHours, int maxHours, vector<int> indToConsider);

    /**
     * Getter/Refiner for number of students. Considers all indecies.
     *
     * @brief getIndicesStudents
     * @param minNumStudents
     * @param maxNumStudents
     * @return
     */
    vector<int> getIndicesStudents(int minNumStudents, int maxNumStudents);

    /**
     * Getter/Refiner for number of students. Considers specified indecies.
     *
     * @brief getIndicesStudents
     * @param minNumStudents
     * @param maxNumStudents
     * @param indToConsider
     * @return
     */
    vector<int> getIndicesStudents(int minNumStudents, int maxNumStudents, vector<int> indToConsider);

    double getHours(int index);

private:
    /*
     * Private Instance Variables
     *
     * These lists of strings and int indices are be maintained in the object to hasten queries.
     */
    vector<string> types;
    vector<vector<int>> typesIndices;

};

#endif // TEACHINGPROCESSING_H
