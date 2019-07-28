# -*- coding: utf-8 -*-
import scrapy
from scrapy import Request
import re


class SpbeenSpider(scrapy.Spider):
    name = 'beike'
    allowed_domains = ['sh.zu.ke.com']#允许抓取的链接域名，域名中含有这个spbeen的才会抓取
    start_urls = ['https://sh.zu.ke.com/zufang']

    def parse(self, response):
        handle_httpstatus_listb = [404]
        #print(response.url)
        #item = {}
        #item['us'] = response.xpath('//*[@id="content"]/div[1]/div[1]').extract_first()
        #item['ip'] = response.xpath('/html/body').extract_first()
        #print(response.url)
        base_url = 'https://sh.zu.ke.com/zufang'
        change_url = response.xpath('//div[contains(@class,"content")]/div/div/div/a/@href').extract()
        print('\n')
        for a in change_url:
            url = base_url+a
        print(url)
        title = response.xpath('//div[contains(@class,"content")]/div/div/div/a/@title').extract()
        print(title)
        next1_url = response.xpath('//*[@id="content"]/div[1]/ul[2]/li/a/@href').extract()
        next1_url.pop()
        for n_url in next1_url:
            next_url = str(base_url) + str(n_url)
            #print(next_url)
        print('\n')
        print(next_url)
        contain_url = response.xpath('//p[contains(@class,"content")]/a/@href').extract()
        for urls in contain_url:
            contain_urls = str(base_url) + str(urls)
            #print(contain_urls)
        #yield Request(next_url)
