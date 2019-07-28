# -*- coding: utf-8 -*-
import scrapy
from scrapy import Request


class NewsSpider(scrapy.Spider):
    name = 'news'
    allowed_domains = ['qq.com']
    start_urls = ['http://news.qq.com/']

    def parse(self, response):
        print(response.body)
        hrefs = response.xpath('//div[contains(@class,"content__pg")]/a/@href').extract()
        print(hrefs)
           # yield Request(href)
