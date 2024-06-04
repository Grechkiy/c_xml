#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libxml/xmlreader.h>
#include <libxml/parser.h>

void getReference(xmlDocPtr doc, xmlNodePtr cur) {

    cur = cur->xmlChildrenNode;
    while (cur != NULL) {
        if ((!xmlStrcmp(cur->name, (const xmlChar *) "reference"))) {
            printf("uri: %s\n", xmlGetProp(cur, "uri"));
        }
        cur = cur->next;
    }
    return;
}

void parseDoc(char *docname) {

    xmlDocPtr doc;
    xmlNodePtr cur;

    printf("%s \n", docname);
    doc = xmlParseFile(docname);

    if (doc == NULL) {
        fprintf(stderr, "Document not parsed successfully. \n");
        return;
    }

    cur = xmlDocGetRootElement(doc);

    if (cur == NULL) {
        fprintf(stderr, "empty document\n");
        xmlFreeDoc(doc);
        return;
    }

    if (xmlStrcmp(cur->name, (const xmlChar *) "story")) {
        fprintf(stderr, "document of hte wrong type, root node != story");
        xmlFreeDoc(doc);
        return;
    }

    getReference(doc, cur);
    xmlFreeDoc(doc);
    return;
}


int main(int argc, char **argv) {

    char *docname;

    /*if (argc <= 1) {
        printf("Usage: %s docname\n", argv[0]);
        return (0);
    }*/

    docname = "D:/Projects/c_xml/cmake-build-debug/simple.xml";
    printf("Parasha: %d \n", argc);
    parseDoc(docname);

    return (1);
}
