#include "IParserTemplateMethod.h"

IParserTemplateMethod::~IParserTemplateMethod() {}

QVariant IParserTemplateMethod::parse(const QString& str) const {
    return str;
}

