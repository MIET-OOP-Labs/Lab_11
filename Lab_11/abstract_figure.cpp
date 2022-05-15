#include "abstract_figure.h"

AbstractFigure::AbstractFigure() {
}

void AbstractFigure::setParams(list<int> newParams) {
    if (newParams.size() != this->paramsNum) {
        return;
    }
	params.assign(newParams.begin(), newParams.end());
};

int AbstractFigure::listGetItem(list<int> _list, int index) {
	list<int>::iterator it = _list.begin();
	for(int i=0; i < index; i++){
		++it;
	}
	return *it;
}

AbstractFigure::~AbstractFigure() {
}
