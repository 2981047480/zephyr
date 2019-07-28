# -*- coding: utf-8 -*-
import scrapy


class BeikeSpider(scrapy.Spider):
    name = 'beike1'
    allowed_domains = ['sh.zu.ke.com']
    start_urls = ['http://sh.zu.ke.com/']

    def parse(self, response):
        print(response.body)
        with open('贝壳租房.html','wb') as fp:
            fp.write(response.body)
