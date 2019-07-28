# -*- coding: utf-8 -*-
import scrapy
from scrapy import Request




class BeikeSpider(scrapy.Spider):
    name = 'beike'
    allowed_domains = ['sh.zu.ke.com']
    start_urls = ['http://sh.zu.ke.com/']

    def parse(self, response):
        def insidepage():
            price1 = response.xpath('//div[contains(@class,"content__aside fr")]/p/span/text()').extract_first()
            print(price1)
            price2 = response.xpath('//div[contains(@class,"content__aside fr")]/p/text()').extract_first()
            print(price2)
            price = str(price1) + str(price2)
            print(price)


        base_url = 'https://sh.zu.ke.com/zufang'
        if (response.url==base_url):
            for href in response.xpath('//*[@id="content"]/div[1]/ul[2]/li/a/@href').extract():
                next_url = str(base_url) + str(href)
                #print(next_url)
                yield Request(next_url)
        elif():
            insidepage()
