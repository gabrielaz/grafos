# Importar librerias
from urllib.request import urljoin
from bs4 import BeautifulSoup
import requests
from urllib.request import urlparse
  
  
# Lista (set) para almacenar urls del mismo dominio - interno  
links_intern = set() #conjunto
input_url = "http://posgradounap.pe/programas-de-doctorado/"
depth = 1
  
# Conjunto de urls con dominio distinto - externo
links_extern = set()
  
  
# metodo para rastrear una url en un sgte nivel 
def rastreoniveles(input_url):
    temp_urls = set()
    current_url_domain = urlparse(input_url).netloc
  
    # crea un objeto beautiful soup para extraer etiquetas html
    beautiful_soup_object = BeautifulSoup(
        requests.get(input_url).content, "html.parser")
  
    # acceder a todas las etiquetas de links en html atag.   
    # y clasificarlas como internas y externas  
    for anchor in beautiful_soup_object.findAll("a"):
        href = anchor.attrs.get("href")
        if(href != "" or href != None):
            href = urljoin(input_url, href)
            href_parsed = urlparse(href)
            href = href_parsed.scheme
            href += "://"
            href += href_parsed.netloc
            href += href_parsed.path
            final_parsed_href = urlparse(href)
            is_valid = bool(final_parsed_href.scheme) and bool(
                final_parsed_href.netloc)
            if is_valid:
                if current_url_domain not in href and href not in links_extern:
                    print("Extern - {}".format(href))
                    links_extern.add(href)
                if current_url_domain in href and href not in links_intern:
                    print("Intern - {}".format(href))
                    links_intern.add(href)
                    temp_urls.add(href)
    return temp_urls
  
  
if(depth == 0):
    print("Intern - {}".format(input_url))
  
elif(depth == 1):
    rastreoniveles(input_url)
  
else:
    # Se usa el enfoque BFS considerando la estructura de grafo, usar una cola basada en  
    # recorrido de links para una profundidad en particular  
    queue = []
    queue.append(input_url)
    for j in range(depth):
        for count in range(len(queue)):
            url = queue.pop(0)
            urls = rastreoniveles(url)
            for i in urls:
                queue.append(i)
